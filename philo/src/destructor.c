#include "philo.h"

void mutex_free(t_mutexes *this, t_arguments args)
{
    int i;

    if (this != NULL)
    {
        i = 0;
        pthread_mutex_destroy((&this->spleepmutex));
        pthread_mutex_destroy((&this->write));
        while(i < args.nof)
        {
            pthread_mutex_destroy(this->forks[i]);
           free(this->forks[i]);
            i++;
        }
       free(this->forks);
    }
}

void free_all(t_arguments args , t_philo **philos)
{
    int i;
    t_mutexes *mutex;

    i = 0;
    mutex = NULL;
    while(i < args.nof)
    {
        mutex = philos[i]->mutex;
        philos[i]->mutex = NULL;
        free(philos[i]);
        i++;
    }
    free(philos);
    if (mutex != NULL)
        mutex->free(mutex, args);
}