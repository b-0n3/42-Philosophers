#include "philo.h"

void philo_think(t_philo *this)
{
   if (this->mutex->one_is_dead || this->dead)
        return;
     write_message("is thinking\n", this->id, this->mutex, 0);
}