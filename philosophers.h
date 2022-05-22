/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:55 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/22 19:49:25 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H   /// The Name has is Singular not Plural
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
// #include <time.h>    //// TO DELETE
#include <sys/time.h>
#include <stdio.h>

struct s_philosopher;

typedef struct s_game
{
	struct s_philosopher **to_philosopher;
	pthread_mutex_t		m_print;
	pthread_mutex_t		*m_forks;  /// It's Size will be Determined by the Number of Philosophers as there are as many forks as Philosophers
	struct timeval		start;

	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals;
	int					end;
	int					game;
} t_game;

typedef struct s_philosopher
{
	pthread_mutex_t			m_eat;
	t_game					*to_game;

	int						last_meal;
	int						meals;
	int						id;
	int						philosopher;					
} t_philosopher;

/* Checkers */
int		is_number_of_args(int argc);
int		is_args_positive(int argc, char **argv);
int		ft_isdigit(int argc, char **argv);

/* Utils */
long	ft_atoi(const char *str);
int	ft_sum(int *arr, int len);
void	print(t_philosopher *philosopher, int msec, char *str);
int		ft_strcmp(char *s1, char *s2, size_t n);

/* Initialising = Putting the Arguments in Structs */
int		initialize_table(t_game *table, int argc, char **argv);
void	initialize_philosophers(t_game *table);
void	initialize_forks(t_game *table);

/* The Play */
void	*dinner(void *philo);
void	dining(t_game *game, t_philosopher *philosopher, int right, int left);
void	dine(t_game *game);

/* Time Keeping */
void	check_dead(t_game *game, t_philosopher *philosopher);
int		get_clock(t_game *game);
void	wake_up(t_game *game, int seconds);


#endif