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
	return ((t_long)cur.tv_sec * 1000000 + (t_long)cur.tv_usec);
}

int main(int argc, char **argv)
{
    t_arguments args;
    t_philo **philos;
    t_mutexes mutexes;

    if (init_arguments(&args, argc, argv))
    {
        print_usage();
        exit(1);
    }
  //  god_bless_philosophers()

}