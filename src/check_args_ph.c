/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_ph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:32:47 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/05 14:51:31 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	VERIFICACIÓN DE ARGUMENTOS:
	1. Si no hay argumentos O si hay de más o 
	de menos --> imprimir instrucciones.
	
	2. Si hay el numero correcto de 
	argumentos --> verificar si el argumento es un num.

	Si los argumentos son válidos (son num), entonces pasar por ft_atol
*/

static void	print_instructions(void)
{
	printf(BYELLOW"\n╔═════════════ PHILO HANDLING ════════════════╗\n");
	printf(BYELLOW"║                                             ║\n");
	printf(BYELLOW"║    ./philosophers                           ║\n");
	printf(BYELLOW"║                                             ║\n");
	printf(BYELLOW"║    ARGUMENT 1 --> number_philosophers       ║\n");
	printf(BYELLOW"║    ARGUMENT 2 --> time_2_die (mseconds)     ║\n");
	printf(BYELLOW"║    ARGUMENT 3 --> time_2_eat (mseconds)     ║\n");
	printf(BYELLOW"║    ARGUMENT 4 --> time_2_sleep (mseconds)   ║\n");
	printf(BYELLOW"║    ARGUMENT 5 --> number_meals (optional)   ║\n");
	printf(BYELLOW"║                                             ║\n");
	printf(BYELLOW"║        Ex: ./philo 5 400  500  200          ║\n");
	printf(BYELLOW"║            ./philo 6 200  400  100  3       ║\n");
	printf(BYELLOW"╚═════════════════════════════════════════════╝\n\n");
}

long	ft_atol(const char *str)
{
	long	i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (str[i] == '+')
		i++;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] != '\0' && is_digit(&str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr);
}

int	is_digit(const char *str)
{
	while (*str)
	{
		if (*str == '+')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	valide_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		print_instructions();
		return (1);
	}
	while (i < ac)
	{
		if (!is_digit(av[i]))
		{
			printf(BRED"Incorrect Arg/s\n"RESET);
			return (1);
		}
		i++;
	}
	return (0);
}
