#include "philo.h"

void philo_eat(t_philo *this)
{
    
    this->mutex->eat(this->mutex, this->left_fork_id, this->right_fork_id);
    printf("%d %d has taken a fork\n", get_current_time(), this->id);
    printf("%d %d  is eating\n", get_current_time(), this->id);
    usleep(this->args.tte);
    this->mutex->finish_eating(this->mutex, this->left_fork_id, this->right_fork_id);
}


void mutex_eat(t_mutexes *this, int left, int right)
{
    pthread_mutex_lock(this->forks[left]);
    pthread_mutex_lock(this->forks[right]);
}

void mutex_finish_eating(t_mutexes *this, int left, int right)
{
    pthread_mutex_unlock(this->forks[left]);
    pthread_mutex_unlock(this->forks[right]);
}