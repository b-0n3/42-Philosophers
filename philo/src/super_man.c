/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:50:13 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:50:14 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(long time)
{
	const long	end = get_current_time() + time;

	while (get_current_time() < end)
	{
	}
}

void	philo_check_death(t_philo *this, void *ptr)
{
	if (get_current_time() > this->last_eat_time + this->args.ttd)
		this->dead = 1;
	else
		this->last_eat_time = get_current_time();
	ptr = NULL;
}

int	check_nb_eat(t_arguments args, t_philo **philos)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < args.nof)
	{
		if (philos[i]->nb_eat >= args.notepme)
			nb++;
		i++;
	}
	return (nb == args.nof);
}

void	write_message(char *str, int id, t_mutexes *mutex, int dead)
{
	const long	time = get_current_time() - mutex->start_time;

	if (mutex == NULL)
		return ;
	pthread_mutex_lock(&(mutex->write));
	printf("%ld %d %s", time, id, str);
	if (!dead)
		pthread_mutex_unlock(&(mutex->write));
}

void	god_bless_philosophers(t_arguments args, t_philo **philos)
{
	int	i;

	while (1)
	{
		i = 0;
		if (args.notepme != -1 && check_nb_eat(args, philos))
		{
			philos[0]->mutex->one_is_dead = 1;
			usleep(100);
			free_all(args, philos);
			return ;
		}
		while (i < args.nof)
		{
			if (philos[i]->dead
				|| (get_current_time()
					> philos[i]->last_eat_time + philos[i]->args.ttd))
				return (burn_dead_philo(philos, i, args));
			i++;
		}
	}
}
