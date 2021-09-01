#include "philo.h"

void philo_eat(t_philo *this)
{
    
    if (this->mutex->one_is_dead)
        exit(0);
    this->mutex->eat(this->mutex, this->left_fork_id, this->right_fork_id);
    write_message("has taken a fork\n", this->id, this->mutex, 0);
    write_message("is eating\n", this->id, this->mutex, 0);
    my_sleep(this->args.tte);
    this->check_death(this);
    this->nb_eat++;
    this->mutex->finish_eating(this->mutex, this->left_fork_id, this->right_fork_id);
   
    
}

void mutex_eat(t_mutexes *this, int left, int right)
{
    sem_wait(this->forks[left]);
    sem_post(this->forks[right]);
}

void mutex_finish_eating(t_mutexes *this, int left, int right)
{
    sem_wait(this->forks[left]);
    sem_post(this->forks[right]);
}