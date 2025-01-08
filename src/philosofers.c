/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:15:44 by lauriane          #+#    #+#             */
/*   Updated: 2025/01/08 20:50:23 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_lifestyle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->num_philo == 1)
	{
		print_status(philo, CIAN"has taken the only fork it has"RESET);
		usleep(philo->table->t2die * 1000);
		return (NULL);
	}
	while (!philo->table->simulation_stop)
	{
		take_forks(philo);
		eat(philo);
		ph_sleep(philo);
		print_status(philo, BYELLOW"is thinking"RESET);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_create(&table->monitor_thread, NULL, monitor, table) != 0)
		return ;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->ph[i].hilo, NULL, philo_lifestyle,
				&table->ph[i]) != 0)
		{
			table->simulation_stop = 1;
			return ;
		}
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->ph[i].hilo, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
}

int	main(int ac, char **av)
{
	t_table		table;

	if (valide_args(ac, av) == 0)
	{
		init_structs(&table, ac, av);
		start_simulation(&table);
		clean_up(&table);
		printf("\n🍽  End of feast sim 🍽\n\n");
	}
	return (0);
}
