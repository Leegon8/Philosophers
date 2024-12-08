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
	while (1)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		ph_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->ph[i].hilo, NULL, philo_lifestyle
			&table->ph[i]) !+ 0)
		{
			printf("Error al crear hilo para filosofo %d\n", i + 1);
			break;
		}
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	valide_args(ac, av);
	init_structs(&table, ac, av);
	start_simulation(&table);
	clean_up(&table);
	return (0);
}
