/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:26 by lauriago          #+#    #+#             */
/*   Updated: 2024/12/08 18:04:23 by lauriago         ###   ########.fr       */
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
typedef struct s_philo		t_philo;
typedef struct s_table		t_table;

/* **************************** Structures ********************************** */
struct	s_philo
{
	int				id;
	pthread_t		hilo;
	int				meals_count;	// Número de comidas realizadas
	pthread_mutex_t	*left_fork;		// Tenedor izquierdo
	pthread_mutex_t	*right_fork;	// Tenedor derecho
	long			last_meal_time;		// Timestamp de la última comida
	int				is_eating;		//Flag del estado de comida
	t_table			*table;			// Puntero a la configuración general
};

struct	s_table
{
	int				num_philo;
	int				must_eat_count;	// Número de comidas objetivo (opcional)
	int				t2die;			// Tiempo máximo sin comer
	int				t2eat;			// Tiempo para comer
	int				t2sleep;		// Tiempo para dormir
	pthread_mutex_t	*forks;			// Arreglo de mutex para tenedores
	pthread_mutex_t	print_mutex;	// Mutex para imprimir logs sin mezclar
	int				simulation_stop;// Bandera para detener la simulación
	long			start_t;			// Start timer
	pthread_t		monitor_thread;		// Monitor thread
	t_philo			*ph;
};

/* **************************** philosophers.c ***************************** */
void	*philo_lifestyle(void *arg);
void	start_simulation(t_table *table);

/* **************************** check_args_ph.c ***************************** */
// int	ft_atoi(const char *str);
long	ft_atol(const char *str);
int		is_digit(const char *str);
int		valide_args(int ac, char **av);

/* ******************************* init_ph.c ******************************** */
int		init_table(t_table *table, int ac, char **av);
int		init_mutex(t_table *table);
void	init_philo(t_table *table);
void	init_structs(t_table *table, int ac, char **av);

/* ***************************** rutine_ph.c ******************************** */
//void	*philo_lifestyle(void arg);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
// void	drop_forks(t_philo *philo);
void	ph_sleep(t_philo *philo);

/* ****************************** utils.c *********************************** */
long	get_timestamp(void);
void	print_status(t_philo *philo, const char *message);
int		check_philo_status(t_table *table, int *i, int *all_ate);
void	*monitor(void *arg);

/* **************************** destroyer_ph.c ****************************** */
void	clean_forks(t_table *table);
void	clean_up(t_table *table);

/* ****************************** colors_def ******************************** */
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
