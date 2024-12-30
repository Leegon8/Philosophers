/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:26:08 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/30 14:41:20 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	print_status(t_philo *philo, const char *message)
{
	long	current_time;

	current_time = get_timestamp() - philo->table->start_t;
	if (philo->table->simulation_stop)
		return;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->simulation_stop)
		printf("[%ld] %d %s\n", current_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while(!table->simulation_stop)
	{
		i = 0;
		while (i < table->num_philo)
		{
			if (get_timestamp() - table->ph[i].last_meal_time >= table->t2die)
			{
				//printf("numero del philo que probablemente este muerto: %d\n", table->ph[i].id);
				print_status(table->ph, BRED"died"RESET);
				table->simulation_stop = 1;
				return (NULL);
            }
            i++;
        }
        usleep(1000); // Pausa corta para evitar consumir demasiados recursos
    }
    return (NULL);
}

