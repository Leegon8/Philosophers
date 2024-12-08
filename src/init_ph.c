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

/*void	init_philo(t_table *table)
{
	int	i;

	i = 0;

	while (i < table->num_philo)
	{
		table->ph[i].id = i + 1;
		if (pthread_create(&table->ph[i].hilo, NULL,
			philo_lifestyle, &table->ph[i]) != 0) //TODO (philo_lifestile)
			{
				printf("Error al crear el hiloo\n");
				exit(EXIT_FAILURE); // FUNCION NO AUTORIZADA !!
			}
		else
			printf("Se ha creado un hilooo\n");
		i++;
	}
}*/

void	init_philo(t_table *table, char **av)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = &table->ph[i];
	philo->t2die = ft_atoi(av[2]);
	philo->t2eat = ft_atoi(av[3]);
	philo->t2sleep = ft_atoi(av[4]);
	while (i < table->num_philo)
	{
		philo->id = i + 1;
		philo->meals_count = 0;
		philo->last_meal_time = 0;
		philo->is_eating = 0;
		philo->table = table;
		philo->left_fork = &table->forks[i];
		philo->right_fork = &table->forks[(i + 1) % table->num_philo];
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
}

void	init_structs(t_table *table, int ac, char **av)
{
	init_table(table, ac, av);
	init_forks(table);
	init_philo(table, av);
}
