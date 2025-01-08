/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:26:08 by lauriane          #+#    #+#             */
/*   Updated: 2025/01/08 15:26:22 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, const char *message)
{
	long	current_time;

	current_time = get_timestamp() - philo->table->start_t;
	if (philo->table->simulation_stop)
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->simulation_stop)
		printf("[%ld] %d %s\n", current_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

int	check_philo_status(t_table *table, int *i, int *all_ate)
{
	long	time;

	pthread_mutex_lock(&table->ph[*i].state_mutex);
	time = get_timestamp() - table->start_t - table->ph[*i].last_meal_time;
	if (time > table->t2die)
	{
		pthread_mutex_unlock(&table->ph[*i].state_mutex);
		print_status(table->ph, BRED"died"RESET);
		table->simulation_stop = 1;
		return (-1);
	}
	if (table->must_eat_count > 0
		&& table->ph[*i].meals_count < table->must_eat_count)
		*all_ate = 0;
	pthread_mutex_unlock(&table->ph[*i].state_mutex);
	(*i)++;
	return (0);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		all_ate;
	int		i;

	table = (t_table *)arg;
	while (!table->simulation_stop)
	{
		i = 0;
		all_ate = 1;
		while (i < table->num_philo)
			if (check_philo_status(table, &i, &all_ate) == -1)
				return (NULL);
		if (table->must_eat_count > 0 && all_ate)
		{
			table->simulation_stop = 1;
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
