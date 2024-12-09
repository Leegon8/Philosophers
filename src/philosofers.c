/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:15:44 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/08 18:47:48 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_lifestyle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->simulation_stop)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		ph_sleep(philo);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->ph[i].hilo, NULL, philo_lifestyle,
			&table->ph[i]) != 0)
		{
			printf("Error al crear hilo para filosofo %d\n", i + 1);
			break;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_table		table;
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	if (valide_args(ac, av) == 0)
	{
		init_structs(&table, ac, av);
		start_simulation(&table);
		if (pthread_create(&monitor_thread, NULL, monitor, &table) != 0)
        {
            printf("Error al crear el hilo de monitoreo\n");
            clean_up(&table);
            return 1;
        }
		// pthread_join(monitor_thread, NULL);
		if (pthread_join(monitor_thread, NULL) != 0)
    {
        printf("Error joining monitor thread\n");
        return (1);
    }
		while (i < table.num_philo)
		{
			pthread_detach(table.ph[i].hilo);
            i++;
		}
		clean_up(&table);
	}
	return (0);
}
