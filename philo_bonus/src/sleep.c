#include "philo.h"

void philo_sleep(t_philo *this)
{
    if (this->mutex->one_is_dead)
        exit(0);
    this->mutex->sleep(this->mutex);
     write_message("is sleeping\n", this->id, this->mutex, 0);
    my_sleep(this->args.tts);
    this->mutex->finish_sleeping(this->mutex);
}
void mutex_sleep(t_mutexes *this)
{
    sem_wait(&(this->spleepmutex));
}
void mutex_finish_sleeping(t_mutexes *this)
{
    sem_post(&(this->spleepmutex));
}