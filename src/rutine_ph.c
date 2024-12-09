/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine_ph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:43:51 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/08 18:48:29 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->left_fork))
		printf("Error al coger el tenedor izquierdo\n");
	print_status(philo, "has taken a fork <");
	if (!pthread_mutex_lock(philo->right_fork))
		printf("Error al coger el tenedor derecho\n");
	print_status(philo, "has taken a fork >");
}

void	eat(t_philo *philo)
{
	// Actualizar el tiempo de la última comida
	philo->last_meal_time = get_current_time();
	print_status(philo, "is eating");
	usleep(philo->table->t2eat * 1000);  // Dormir durante el tiempo de comer
	philo->meals_count++;  // Incrementar el contador de comidas
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_status(philo, "has taken a fork <");
}

void	ph_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->t2sleep * 1000);
}
