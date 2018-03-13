#include "push_swap.h"

#include <strings.h>

#include <stdlib.h>

int in_one_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= ' ')
			return (1);
		i++;
	}
	return (0);
}

void print_matr(char **matr)
{
	int i;

	i = 0;
	while (matr[i])
	{
		//printf("%s\n", matr[i]);
		i++;
	}
}

int	len_int(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void free_matrics(char ***matr)
{
	int i;

	i = 0;
	while ((*matr)[i])
	{
		free((*matr)[i]);
		i++;
	}
	free(*matr);
}

int read_numbers_from_str(t_stack **a, int size, char **numbers)
{
	int q;
	int i;

	i = 0;
	while (i < size)
	{
		q = ft_atoi(numbers[i]);
		if (strlen(numbers[i]) >= 14 || q != (long long)(int)q)
			return (0);
		if (strlen(numbers[i]) != len_int(q)  || (q == 0 &&  numbers[i][0] != '0'))
			return(0);
		push_back(a, q);
		i++;
	}
	return (1);
}

int read_numbers(t_stack **a, int size, char **numbers)
{
	int q;
	int i;

	i = 0;
	while (i < size)
	{
		q = ft_atoi(numbers[i]);
		if (strlen(numbers[i]) >= 12 || q != (long long)(int)q)
			return (0);
		if (strlen(numbers[i]) != len_int(q)  || (q == 0 &&  numbers[i][0] != '0'))
			return(i);
		push_back(a, q);
		i++;
	}
	return (i);
}

int read_stack_from_str(t_stack **a, char *str)
{
	char **numbers;
	int res;
	int size;

	numbers = ft_strsplit(str, &size);
	res = read_numbers_from_str(a, size, numbers);
	return ((int)(res > 0));
}

int read_stack_a(t_stack **a, int argc, char **argv)
{
	int is_valid;

	if (in_one_str(argv[1]))
		is_valid = read_stack_from_str(a, argv[1]);
	else
		is_valid = read_numbers(a, argc - 1, argv + 1);
	return (is_valid);
}