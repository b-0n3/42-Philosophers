#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>

#define INT32_MAX 2147483647

typedef struct s_arguments
{
    int nof;
    int ttd;
    int tte;
    int tts;
    int notepme;
}   t_arguments;

typedef struct s_mutexes
{
    pthread_mutex_t spleepmutex;
    pthread_mutex_t thinkmutex;
    pthread_mutex_t *forks;

    void (*sleep)(struct s_mutexes);
    void (*think)(struct s_mutexes);
    void (*eat)(struct s_mutexes, int left, int right);
    void (*finish_sleeping)(struct s_mutexes);
    void (*finish_thinking)(struct s_mutexes);
    void (*finsh_eating)(struct s_mutexes, int left, int right);
}               t_mutexes;

typedef struct s_philo
{
    int id;
    int left_fork_id;
    int right_fork_id;
    int last_eat_time;
    int dead;
    int nb_eat;
    void (*eat)(struct s_philo *this);
    void (*think)(struct s_philo *this);
    void (*sleep)(struct s_philo *this);
}   t_philo;

void philo_eat( t_philo *this);
void philo_think( t_philo *this);
void philo_sleep( t_philo *this);
void mutex_sleep( t_mutexes);
void mutex_think( t_mutexes);
void mutex_eat( t_mutexes, int left, int right);
void mutex_finish_sleeping( t_mutexes);
void mutex_finish_thinking( t_mutexes);
void mutex_finsh_eating( t_mutexes, int left, int right);
int init_arguments(t_arguments *this, int argc, char **argv);

#endif