/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:50:05 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:50:07 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *this, void *ptr)
{
	if (this->mutex->one_is_dead || this->dead || ptr != NULL)
		return ;
	write_message("is sleeping\n", this->id, this->mutex, 0);
	my_sleep(this->args.tts);
}
