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
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->simulation_stop)
		printf("[%ld] %d %s\n", current_time, philo->id, message);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

// static int	check_philosopher_status(t_table *table, int *all_ate_enough)
// {
// 	int i;

// 	i = 0;
// 	*all_ate_enough = 1;
// 	while (i < table->num_philo)
// 	{
// 		if (get_timestamp() - table->ph[i].last_meal_time > table->t2die)
// 		{
// 			print_status(&table->ph[i], BRED"died"RESET);
// 			return (1);
// 		}
// 		if (table->must_eat_count > 0 && table->ph[i].meals_count < table->must_eat_count)
// 			*all_ate_enough = 0;
// 		i++;
// 	}
// 	return (0);
// }

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
			pthread_mutex_lock(&table->print_mutex);
			printf("mutex lock\n");
			if (get_timestamp() - table->ph[i].last_meal_time > table->t2die)
			{
				printf("HOLAAAA\n");
				print_status(&table->ph[i], BRED"died"RESET);
				// printf("[%ld] %d has died\n", get_timestamp() - table->start_t, table->ph[i].id);
                table->simulation_stop = 1;
				clean_up(table);
				break;
            }
            pthread_mutex_unlock(&table->print_mutex);
			printf("mutex unlock\n");
            i++;
        }
        usleep(1000); // Pausa corta para evitar consumir demasiados recursos
    }
    return NULL;
}

// void	*monitor(void *arg)
// {
// 	t_table	*table;
// 	int	all_ate_enough;

// 	table = (t_table *)arg;
// 	while (!table->simulation_stop)
// 	{
// 		if (check_philosopher_status(table, &all_ate_enough) == 1)
// 		{
// 			table->simulation_stop = 1;
// 			printf(RED"END SIMULATION\n"RESET);
// 			return (NULL);
// 		}
// 		if (table->must_eat_count > 0 && all_ate_enough)
// 		{
// 			table->simulation_stop = 1;
// 			printf("END SIMULATION\n");
// 			return (NULL);
// 		}
// 		usleep(1000);
// 	}
// 	return (NULL);
// }
