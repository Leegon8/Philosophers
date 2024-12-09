/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:29:16 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/08 17:51:30 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		table->ph[i].id = i + 1;
		table->ph[i].meals_count = 0;
		table->ph[i].last_meal_time = 0;
		table->ph[i].is_eating = 0;
		table->ph[i].table = table;
		table->ph[i].left_fork = &table->forks[i];
		table->ph[i].right_fork = &table->forks[(i + 1) % table->num_philo];
		i++;
	}
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			printf("Error al inicialilzar tenedor %d\n", i);
			break;
		}
		i++;
	}
}

void	init_table(t_table *table, int ac, char **av)
{
	table->num_philo = ft_atoi(av[1]);
	table->ph = malloc(sizeof(t_philo) * table->num_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->ph || !table->forks)
	{
		printf("Error: Memoria insuficiente\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 6)
		table->must_eat_count = ft_atoi(av[5]);
	table->simulation_stop = 0;
	table->t2die = ft_atoi(av[2]);
	table->t2eat = ft_atoi(av[3]);
	table->t2sleep = ft_atoi(av[4]);
}

void	init_structs(t_table *table, int ac, char **av)
{
	init_table(table, ac, av);
	init_forks(table);
	init_philo(table);
}
