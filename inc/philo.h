/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:26 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/03 16:27:25 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/* ************************ Struct simplification *************************** */
typedef struct s_philo  	t_philo;
typedef struct s_table		t_table;

/* ***************************** Structures ********************************* */
struct	s_philo
{
	int				id;
	pthread_t		hilo;
	int				t2die;			// Tiempo máximo sin comer
	int				t2eat;			// Tiempo para comer
	int				t2sleep;		// Tiempo para dormir
	int				meals_count;	// Número de comidas realizadas
	pthread_mutex_t	*left_fork;		// Tenedor izquierdo
	pthread_mutex_t	*right_fork;	// Tenedor derecho
	long long		last_meal_time;	// Timestamp de la última comida
	int				is_eating;		//Flag del estado de comida
	t_table			*table;			// Puntero a la configuración general
};

struct	s_table
{
	int				num_philo;
	int				must_eat_count;	// Número de comidas objetivo (opcional)
	t_philo			*ph;
	pthread_mutex_t	*forks;			// Arreglo de mutex para tenedores
	pthread_mutex_t	print_mutex;	// Mutex para imprimir logs sin mezclar
	int				simulation_stop;// Bandera para detener la simulación
};

/* **************************** check_args_ph.c ***************************** */
int	ft_atoi(const char *str);
int	is_digit(const char *str);
void	init_struct(int ac, char **av, t_philo *ph);
int	valide_args(int ac, char **av);


# define BGRAY "\033[1;90m"
# define BRED "\033[1;91m"
# define BGREEN "\033[1;92m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;94m"
# define BCIAN "\033[1;96m"
# define BWHITE "\033[1;97m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define CIAN "\033[0;96m"
# define WHITE "\033[0;97m"
# define PURPLE "\033[0;95m"
# define BOLD "\033[1m"
# define PHA "\e[1;107;94m"
# define MOU "\e[1;97;44m"
# define RES "\e[0m"
# define RESET "\033[0m"

#endif
