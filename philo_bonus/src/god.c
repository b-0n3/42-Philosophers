#include "philo.h"

void philo_check_death(t_philo *this)
{
    if (get_current_time() > this->last_eat_time + this->args.ttd)
        this->dead = 1;
    else
        this->last_eat_time = get_current_time();
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
        free(philos[i]);
        i++;
    }
    free(philos);
    if (mutex != NULL)
    {
        i = 0;
        sem_close((&mutex->spleepmutex));
        sem_close((&mutex->write));
        while(i < args.nof)
        {
            sem_close(mutex->forks[i]);
            free(mutex->forks[i]);
            i++;
        }
        free(mutex->forks);
    }
}
int  check_nb_eat(t_arguments args ,t_philo **philos)
{
    int i;
    int nb;

    nb = 0;
    i = 0;
    while (i < args.nof)
    {
        if (philos[i]->nb_eat >= args.notepme)
            nb++;
        i++;
    }
    return (nb == args.nof);
}

void write_message(char *str, int id, t_mutexes *mutex, int dead)
{
    sem_wait(&(mutex->write));
    printf("%ld %d %s", get_current_time(), id, str);
    if (!dead)
        sem_post(&(mutex->write));

}
void god_bless_philosophers(t_arguments args , t_philo **philos)
{
    int i;
    int d;

    d = 0;
    while (1)
    {
        i = 0;
        if (args.notepme != -1 && check_nb_eat(args , philos))
        {
            free_all(args, philos);
            return ;
        }
        while (i < args.nof)
        {
            if (philos[i]->dead)
            {
                philos[i]->mutex->one_is_dead = 1;
                write_message("is dead\n", philos[i]->id, philos[i]->mutex, 1);
                free_all(args, philos);
               return;
            }
            i++;
        }
        
    }
}
