/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:50:34 by aait-ham          #+#    #+#             */
/*   Updated: 2021/09/05 19:18:46 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define INT32_MAX 2147483647

typedef struct s_arguments
{
	int	nof;
	int	ttd;
	int	tte;
	int	tts;
	int	notepme;
}	t_arguments;

typedef struct s_mutexes
{
	pthread_mutex_t		spleepmutex;
	pthread_mutex_t		**forks;
	pthread_mutex_t		write;
	void				(*free)(struct s_mutexes *this, t_arguments args);
	void				(*eat)(struct s_mutexes *this, int left, int right);
	void				(*finish_eating)(struct s_mutexes *this,
						int left, int right);
	int					one_is_dead;
	long				start_time;
}		t_mutexes;

typedef struct s_philo
{
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	pthread_t	thread;
	t_mutexes	*mutex;
	t_arguments	args;
	long		last_eat_time;
	int			dead;
	int			nb_eat;
	void		(*check_death)(struct s_philo *this, void *ptr);
	void		(*eat)(struct s_philo *this, void *ptr);
	void		(*think)(struct s_philo *this, void *ptr);
	void		(*sleep)(struct s_philo *this, void *ptr);
}		t_philo;

void	burn_dead_philo(t_philo **philos, int i, t_arguments args);
void	mutex_free(t_mutexes *this, t_arguments args);
void	write_message(char *str, int id, t_mutexes *mutex, int dead);
void	my_sleep(long time);
long	get_current_time(void);
void	philo_eat(t_philo *this, void *ptr);
void	philo_think(t_philo *this, void *ptr);
void	philo_sleep(t_philo *this, void *ptr);
void	philo_check_death(t_philo *this, void *ptr);
void	mutex_eat(t_mutexes *this, int left, int right);
void	god_bless_philosophers(t_arguments args, t_philo **philos);
void	mutex_finish_eating(t_mutexes *this, int left, int right);
int		init_arguments(t_arguments *this, int argc, char **argv);
int		init_mutexes(t_mutexes *mutexes, t_arguments args);
t_philo	*new_philo(t_arguments args, int id);
t_philo	**create_philosofers(t_arguments args);
void	free_all(t_arguments args, t_philo **philos);

#endif
