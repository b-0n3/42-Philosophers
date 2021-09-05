/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:48:38 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:48:43 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_usage(void)
{
	printf("usage:\n");
	printf("./philo number_of_philosophers time_to_die time_to_eat %s",
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

long	get_current_time(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000 + cur.tv_usec / 1000);
}

void	*luanch_thread(void *item)
{
	t_philo	*this;

	this = (t_philo *) item;
	while (1)
	{
		if (this->mutex->one_is_dead)
			return (NULL);
		this->eat(this, NULL);
		this->sleep(this, NULL);
		this->think(this, NULL);
	}
	return (NULL);
}

int	luanch_sumulation(t_arguments args, t_philo **philos, t_mutexes *mutexes)
{
	int	i;

	i = 0;
	mutexes->start_time = get_current_time();
	while (i < args.nof)
	{
		philos[i]->args = args;
		philos[i]->mutex = mutexes;
		philos[i]->last_eat_time = get_current_time();
		pthread_create(&(philos[i]->thread), NULL, &luanch_thread,
			 (void *)philos[i]);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_arguments	args;
	t_philo		**philos;
	t_mutexes	mutexes;

	if (!init_arguments(&args, argc, argv))
	{
		print_usage();
		return (1);
	}
	if (args.nof <= 0)
		return (0);
	if (!init_mutexes(&mutexes, args))
	{
		printf("error\n");
		return (1);
	}
	philos = create_philosofers(args);
	if (philos == NULL)
	{
		mutexes.free(&mutexes, args);
		return (1);
	}
	luanch_sumulation(args, philos, &mutexes);
	god_bless_philosophers(args, philos);
	return (0);
}
