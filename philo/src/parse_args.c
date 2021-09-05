#include "philo.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\f' || c == ' '
		|| c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi( char *str)
{
	int			i;
	long long	n;
	int			signe;

	n = 0;
	i = 0;
	signe = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (str[i] >= '0' && (str[i] <= '9') && str[i] != '\0')
	{
		if (((n * 10) > INT32_MAX) || (n > INT32_MAX)
			|| ((n == INT32_MAX)
				&& (n % 10) > 7))
			return (INT32_MAX);
		n = n * 10 + (*(str + (i++)) - '0');
	}
	return ((int)n * signe);
}

int check_values(t_arguments *this)
{
    return !(this->nof == INT32_MAX 
    || this->ttd == INT32_MAX
    || this->tte == INT32_MAX
    || this->tts == INT32_MAX
    || this->notepme == INT32_MAX);
}

int  init_arguments(t_arguments *this, int argc, char **argv)
{
    if (this == NULL || argv == NULL || argc < 5 || argc > 6)
        return 0;
    this->nof = ft_atoi(argv[1]);
    this->ttd = ft_atoi(argv[2]);
    this->tte= ft_atoi(argv[3]);
    this->tts = ft_atoi(argv[4]);
    if (argc == 6)
        this->notepme = ft_atoi(argv[5]);
    else
        this->notepme = -1;
    return (check_values(this));
}