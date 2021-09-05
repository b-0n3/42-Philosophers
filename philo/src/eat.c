/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:49:10 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:49:30 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *this, void *ptr)
{
	if (this->mutex->one_is_dead || ptr != NULL)
		return ;
	if (this->args.nof == 1)
	{
		my_sleep(this->args.tte + this->args.tts);
		this->dead = 1;
		return ;
	}
	this->mutex->eat(this->mutex, this->left_fork_id, this->right_fork_id);
	write_message("has taken a fork\n", this->id, this->mutex, 0);
	write_message("is eating\n", this->id, this->mutex, 0);
	my_sleep(this->args.tte);
	this->check_death(this, NULL);
	this->nb_eat++;
	this->mutex->finish_eating(this->mutex,
		this->left_fork_id, this->right_fork_id);
}

void	mutex_eat(t_mutexes *this, int left, int right)
{
	pthread_mutex_lock(this->forks[left]);
	pthread_mutex_lock(this->forks[right]);
}

void	mutex_finish_eating(t_mutexes *this, int left, int right)
{
	pthread_mutex_unlock(this->forks[left]);
	pthread_mutex_unlock(this->forks[right]);
}
