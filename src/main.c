/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriane <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:15:44 by lauriane          #+#    #+#             */
/*   Updated: 2024/12/04 18:15:47 by lauriane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	memset(&philo, 0, sizeof(t_philo));
	if (valide_args(ac, av))
		init_struct(ac, av, &philo);
	if (philo.table)
		free(philo.table);
	return (0);
}
