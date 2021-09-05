#include "philo.h"

int init_mutexes(t_mutexes *mutexes, t_arguments args)
{
    int i;

    i = 0;
    if (mutexes == NULL)
        return 0;
    mutexes->forks = (pthread_mutex_t **)malloc ((args.nof + 1) * sizeof(pthread_mutex_t *));
    if (mutexes->forks == NULL)
        return 0;

    pthread_mutex_init(&(mutexes->spleepmutex), NULL);
    pthread_mutex_init(&(mutexes->write), NULL);
    while (i <= args.nof)
    {
        mutexes->forks[i] = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(mutexes->forks[i], NULL);
        i++;
    }
    mutexes->one_is_dead = 0;
    mutexes->eat = &mutex_eat;
    mutexes->sleep = &mutex_sleep;
    mutexes->finish_sleeping = &mutex_finish_sleeping;
    mutexes->free = &mutex_free;
    mutexes->finish_eating = &mutex_finish_eating;
    return 1;
}


t_philo *new_philo(t_arguments args, int id)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo ));
    if (philo == NULL)
        return (NULL);
    philo->id = id;
    philo->dead = 0;
    philo->last_eat_time = get_current_time();
    philo->left_fork_id = (id - 1) % args.nof; 
    philo->right_fork_id = id % args.nof;
    philo->nb_eat = 0;
    philo->check_death = &philo_check_death;
    philo->eat = &philo_eat;
    philo->think = &philo_think;
    philo->sleep = &philo_sleep;
    return philo;
}

t_philo **create_philosofers(t_arguments args)
{
    t_philo **list;
    int i;
 
    list = (t_philo **)malloc(args.nof * sizeof(t_philo *));
    if (list == NULL)
        return (NULL);
    i = 0;
    while (i < args.nof)
    {
        list[i] = new_philo(args, i + 1);
        if (list[i] == NULL)
        {
            while (--i >= 0)
                free(list[i]);
            free(list);
            return NULL;
        }
        i++;
    }
    return (list);
}
