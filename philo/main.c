#include "philo.h"


void print_usage()
{
    printf("usage:\n");
    printf("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep %s",
    "[number_of_times_each_philosopher_must_eat]\n");
}


int main(int argc, char **argv)
{
    t_arguments args;

    if (init_arguments(&args, argc, argv))
    {
        print_usage();
        exit(1);
    }

}