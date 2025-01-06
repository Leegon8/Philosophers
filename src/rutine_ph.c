/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine_ph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:43:51 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/30 14:37:25 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, CIAN"has taken a fork >"RESET);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, BLUE"has taken a fork <"RESET);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, BLUE"has taken a fork <"RESET);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, CIAN"has taken a fork >"RESET);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	philo->is_eating = 1;
	philo->last_meal_time = get_timestamp() - philo->table->start_t;
	philo->meals_count++;
	pthread_mutex_unlock(&philo->table->print_mutex);
	print_status(philo, BGREEN"is eating"RESET);
	usleep(philo->table->t2eat * 1000);
	philo->is_eating = 0;
}

void	ph_sleep(t_philo *philo)
{
	print_status(philo, PURPLE"is sleeping"RESET);
	usleep(philo->table->t2sleep * 1000);
}
