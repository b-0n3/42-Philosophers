#include "philo.h"

void philo_sleep(t_philo *this)
{
    if (this->mutex->one_is_dead || this->dead)
        return;
 //   this->mutex->sleep(this->mutex);
     write_message("is sleeping\n", this->id, this->mutex, 0);
    my_sleep(this->args.tts);
  //  this->mutex->finish_sleeping(this->mutex);
}
void mutex_sleep(t_mutexes *this)
{
    pthread_mutex_lock(&(this->spleepmutex));
}
void mutex_finish_sleeping(t_mutexes *this)
{
    pthread_mutex_unlock(&(this->spleepmutex));
}