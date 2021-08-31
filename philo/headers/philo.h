#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
 #include <unistd.h>

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
    pthread_mutex_t **forks;
    pthread_mutex_t write;
     int one_is_dead;
    void (*sleep)(struct s_mutexes *this);
 
    void (*eat)(struct s_mutexes *this, int left, int right);
    void (*finish_sleeping)(struct s_mutexes *this);
    void (*finish_eating)(struct s_mutexes *this, int left, int right);
}               t_mutexes;

typedef struct s_philo
{
    int id;
    int left_fork_id;
    int right_fork_id;
    pthread_t thread;
    t_mutexes  *mutex;
    t_arguments args;
   
    long last_eat_time;
    int dead;
    int nb_eat;
    void (*check_death)(struct s_philo *this);
    void (*eat)(struct s_philo *this);
    void (*think)(struct s_philo *this);
    void (*sleep)(struct s_philo *this);
}   t_philo;

void write_message(char *str, int id, t_mutexes *mutex, int dead);
void my_sleep(long time);
long		get_current_time(void);
void philo_eat(t_philo *this);
void philo_think(t_philo *this);
void philo_sleep(t_philo *this);
void mutex_sleep(t_mutexes *this);
void philo_check_death(t_philo *this);
void mutex_eat(t_mutexes *this, int left, int right);
void mutex_finish_sleeping( t_mutexes *this);
void god_bless_philosophers(t_arguments args , t_philo **philos);
void mutex_finish_eating(t_mutexes *this, int left, int right);
int init_arguments(t_arguments *this, int argc, char **argv);
int init_mutexes(t_mutexes *mutexes, t_arguments args);
t_philo *new_philo(t_arguments args, int id);
t_philo **create_philosofers(t_arguments args);

#endif