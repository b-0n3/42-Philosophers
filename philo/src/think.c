/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:50:23 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 18:50:24 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *this, void *ptr)
{
	if (this->mutex->one_is_dead || this->dead || ptr != NULL)
		return ;
	  write_message("is thinking\n", this->id, this->mutex, 0);
}
