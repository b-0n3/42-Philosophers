#include "philo.h"


void print_usage()
{
    printf("usage:\n");
    printf("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep %s",
    "[number_of_times_each_philosopher_must_eat]\n");
}

t_long		get_current_time(void)
{
	struct timeval cur;

	gettimeofday(&cur, NULL);
    // *1000000
	return ((t_long)cur.tv_sec  + (t_long)cur.tv_usec);
}

void luanch_thread(void *item)
{
    t_philo *this;

    this = (t_philo *) item;
    while(1)
    {
        this->eat(this);
        this->sleep(this);
        this->think(this);
    }
}

int luanch_sumulation(t_arguments args , t_philo **philos, t_mutexes *mutexes)
{
        int i;

        i = 0;
        while (i < args.nof)
        {
            philos[i]->mutex = mutexes;
            pthread_create(&philos[i]->thread, NULL , &luanch_thread,(void *)philos[i]);
            i++;
        }
}

int main(int argc, char **argv)
{
    t_arguments args;
    t_philo **philos;
    t_mutexes mutexes;

    if (!init_arguments(&args, argc, argv))
    {
        print_usage();
        exit(1);
    }
    if(!init_mutexes(&mutexes, args))
    {
        printf("error\n");
        exit(1);
    }
    philos= create_philosofers(args);
    if(philos == NULL)
    {
        //   remember to freee all that shit 
        exit(1);
    }
    
    luanch_sumulation(args , philos, &mutexes);
    god_bless_philosophers(args , philos);
    return (0);
}