#include "push_swap.h"
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
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
		printf("%s\n", matr[i]);
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
		if (strlen(numbers[i]) >= 14 || q != (long long)(int)q)
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

int 	read_and_do_operations(t_stack **a, t_stack **b, char **operations, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!strcmp(operations[i], "sa"))
			do_s(a);
		else if (!strcmp(operations[i], "sb"))
			do_s(b);
		else if (!strcmp(operations[i], "ss"))
			do_ss(a, b);
		else if (!strcmp(operations[i], "pa"))
			do_p(a, b);
		else if (!strcmp(operations[i], "pb"))
			do_p(b, a);
		else if (!strcmp(operations[i], "ra"))
			do_r(a);
		else if (!strcmp(operations[i], "rb"))
			do_r(b);
		else if (!strcmp(operations[i], "rr"))
			do_rr(a, b);
		else if (!strcmp(operations[i], "rra"))
			do_rra(a);
		else if (!strcmp(operations[i], "rrb"))
			do_rra(b);
		else if (!strcmp(operations[i], "rrr"))
			do_rrr(a, b);
		else
			return (0);
		i++;
	}
	return (1);
}

void is_sorted(t_stack *a, t_stack *b)
{
	if (b)
	{
		write (1, "KO\n", 3);
		return ;
	}
	while(a->next)
	{
		if (a->data > a->next->data)
		{
			write (1, "KO\n", 3);
			return ;
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int is_valid;

	a = NULL;
	b = NULL;
	is_valid = (argc != 1) ? 1 : 0;
	is_valid = is_valid ? read_stack_a(&a, argc, argv) : 0;
	is_valid = is_valid ? read_and_do_operations(&a, &b, argv + is_valid + 1, argc - 1 - is_valid) : 0;
	is_valid = is_valid? is_duplicats(a) : 0;
	if (is_valid)
		is_sorted(a, b);
	if (!is_valid)
		write(1, "error\n", 6);
	del_two_stacks(&a, &b);

	//print_stack(a);
	//print_stack(b);
	return (0);
}