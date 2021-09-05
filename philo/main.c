#include "philo.h"


void print_usage()
{
    printf("usage:\n");
    printf("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep %s",
    "[number_of_times_each_philosopher_must_eat]\n");
}

long		get_current_time(void)
{
	struct timeval cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000  + cur.tv_usec / 1000);
}

void *luanch_thread(void *item)
{
    t_philo *this;

    this = (t_philo *) item;
    while(1)
    {
        if (this->mutex->one_is_dead)
            return NULL;
       
        this->eat(this);
        this->sleep(this);
        this->think(this);
    }
    return NULL;
}

void my_sleep(long time)
{
    const long end = get_current_time() + time;   
    while (get_current_time() < end); 
}

int luanch_sumulation(t_arguments args , t_philo **philos, t_mutexes *mutexes)
{
        int i;

        i = 0;
        mutexes->start_time = get_current_time();
        while (i < args.nof)
        {
            philos[i]->args = args;
            philos[i]->mutex = mutexes;
            philos[i]->last_eat_time = get_current_time();
            pthread_create(&(philos[i]->thread), NULL , &luanch_thread, (void *)philos[i]);
            i++;
        }
    
    return (1);
}

int main(int argc, char **argv)
{
    t_arguments args;
    t_philo **philos;
    t_mutexes mutexes;

    if (!init_arguments(&args, argc, argv))
    {
        print_usage();
        return (1);
    }
    if (args.nof <= 0)
        return 0;
    if(!init_mutexes(&mutexes, args))
    {
        printf("error\n");
        return (1);
    }
    philos = create_philosofers(args);
    if(philos == NULL)
    {
        mutexes.free(&mutexes, args);
       return (1);
    }
    luanch_sumulation(args , philos, &mutexes);
    god_bless_philosophers(args , philos);
    return (0);
}