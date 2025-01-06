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

int	init_table(t_table *table, int ac, char **av)
{
	memset(table, 0, sizeof(t_table));
	if (!table)
		return (-1);
	table->num_philo = ft_atol(av[1]);
	table->ph = malloc(sizeof(t_philo) * table->num_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->ph || !table->forks)
		return (-1);
	table->simulation_stop = 0;
	table->t2die = ft_atol(av[2]);
	table->t2eat = ft_atol(av[3]);
	table->t2sleep = ft_atol(av[4]);
	if (ac == 6)
		table->must_eat_count = ft_atol(av[5]);
	table->start_t = get_timestamp();
	return (0);
}

int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (-1);
	while (i < table->num_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			clean_forks(table);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		table->ph[i].id = i + 1;
		table->ph[i].meals_count = 0;
		table->ph[i].last_meal_time = get_timestamp() - table->start_t;
		table->ph[i].is_eating = 0;
		table->ph[i].table = table;
		table->ph[i].left_fork = &table->forks[i];
		table->ph[i].right_fork = &table->forks[(i + 1) % table->num_philo];
		i++;
	}
}

void	init_structs(t_table *table, int ac, char **av)
{
	if (init_table(table, ac, av) == -1)
	{
		clean_up(table);
		return ;
	}
	if (init_mutex(table) == -1)
	{
		clean_up(table);
		return ;
	}
	init_philo(table);
}
