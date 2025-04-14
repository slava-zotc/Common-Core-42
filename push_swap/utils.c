#include "stack.h"

int count_str_argv(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	isvalid_minus(char *argv, int j)
{
	return (argv[j] == '-' && (j == 0 || argv[j - 1] == ' ')
			&& ft_isdigit(argv[j + 1]));
}

void print_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atoi_ower(const char *str)
{
	size_t			i;
	int				sign;
	long			res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		print_error();
	return (res * sign);
}

