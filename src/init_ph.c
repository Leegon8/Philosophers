/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:29:16 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/05 15:14:05 by lauriago         ###   ########.fr       */
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
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
	{
		table->ph[i].left_fork = &table->forks[i];
		table->ph[i].right_fork = &table->forks[(i + 1) % table->num_philo];
	}
}

void	init_struct(int ac, char **av, t_philo *ph)
{
	t_table	table;

	ph->table = malloc(sizeof(t_table));
	if (!ph->table)
		return ;
	memset(&table, 0, sizeof(t_table));
	if (ac >= 4)
	{
		ph->table->num_philo = ft_atoi(av[1]);
		ph->t2die = ft_atoi(av[2]);
		ph->t2eat = ft_atoi(av[3]);
		ph->t2sleep = ft_atoi(av[4]);
	}
	if (ac == 6)
		ph->table->must_eat_count = ft_atoi(av[5]);
	init_forks(&table);
	init_philo(&table);
}
