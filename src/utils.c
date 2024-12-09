/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:26:08 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/09 17:26:23 by lauriane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

void	print_status(t_philo *philo, const char *message)
{
	long long	current_time;

	current_time = get_current_time() - philo->table->start_t;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->simulation_stop)
		printf("%lld %d %s\n", current_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

static int	check_philosopher_status(t_table *table, int *all_ate_enough)
{
	int i;

	i = 0;
	*all_ate_enough = 1;
	while (i < table->num_philo)
	{
		if (get_current_time() - table->ph[i].last_meal_time > table->t2die)
		{
			print_status(&table->ph[i], "died");
			return (1);
		}
		if (table->must_eat_count > 0 && table->ph[i].meals_count < table->must_eat_count)
			*all_ate_enough = 0;
		i++;
	}
	return (0);
}
void	*monitor(void *arg)
{
	t_table	*table;
	int	all_ate_enough;

	table = (t_table *)arg;
	while (!table->simulation_stop)
	{
		if (check_philosopher_status(table, &all_ate_enough))
		{
			table->simulation_stop = 1;
			return (NULL);
		}
		if (table->must_eat_count > 0 && all_ate_enough)
		{
			table->simulation_stop = 1;
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
