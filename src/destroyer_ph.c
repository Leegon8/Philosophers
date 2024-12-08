/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer_ph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:56:31 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/08 18:01:56 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_table *table)
{
	if (table->ph)
	{
		free(table->ph);
		table->ph = NULL;
	}
	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
}
