/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/22 19:44:50 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* number_of_philosophers time_to_die time_to_eat time_to_sleep meals(number_of_times_each_philosopher_must_eat) */

int	main(int argc, char **argv)
{
	t_game			game;
	pthread_t		*thread;
	t_philosopher	*philosopher;
	int				i;

	i = 0;

	/* if (!is_number_of_args(argc) || !is_args_positive(argc, argv) || !ft_isdigit(argc, argv)) */
	// if (!is_number_of_args(argc) || !ft_isdigit(argc, argv))
	if (!is_number_of_args(argc))
		return (-1);
	if (!initialize_table(&game, argc, argv))
		return (-2);
	thread = malloc(sizeof(pthread_t *) * game.number_of_philos);
	if (!thread)
		return (-3);
	/* Creating the Threads */
	while (i < game.number_of_philos)
	{
		philosopher = game.to_philosopher[i];
		pthread_create(&thread[i], NULL, &dinner, philosopher);
		i++;
	}

	printf("Reached the end of Main");
	return (0);
}




/////   For Learning Purposes   ////
/*
int mails = 0;
pthread_t mutex;

void	*routine()
{
	int i;
	
	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	// printf("Test\n");
	// sleep(2);
	// printf("Second Print\n");
}


int		main()
{
	pthread_t t[4];
	int		i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&t[i], NULL, &routine, NULL) != 0)
		{
			return (1);
		}
		printf("Thread %d Created\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(t[i], NULL) != 0)
		{
			return 2;
		}
		printf("Finished Joining Thread %d\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("The Final Number of %d\n", mails);
	return(0);
} */