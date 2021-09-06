/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:48:58 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:49:38 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_free(t_mutexes *this, t_arguments args)
{
	int	i;

	if (this != NULL)
	{
		i = 0;
		pthread_mutex_destroy((&this->spleepmutex));
		pthread_mutex_destroy((&this->write));
		while (i < args.nof)
		{
			pthread_mutex_destroy(this->forks[i]);
			free(this->forks[i]);
			i++;
		}
		free(this->forks);
	}
}

void	burn_dead_philo(t_philo **philos, int i, t_arguments args)
{
	philos[i]->dead = 1;
	write_message("is dead\n", philos[i]->id, philos[i]->mutex, 1);
	philos[i]->mutex->one_is_dead = 1;
	usleep(100);
	free_all(args, philos);
}

void	free_all(t_arguments args, t_philo **philos)
{
	int			i;
	t_mutexes	*mutex;

	i = 0;
	mutex = NULL;
	while (i < args.nof)
	{
		mutex = philos[i]->mutex;
		philos[i]->mutex = NULL;
		free(philos[i]);
		i++;
	}
	free(philos);
	if (mutex != NULL)
		mutex->free(mutex, args);
}
