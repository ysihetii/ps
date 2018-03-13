#include "push_swap.h"
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void parr(int *arr, int n)
{
		printf("\nn=%i\n", n);
	for (int i = 0; i < n; i++)
		printf("\narr=[%i]=%i", i, arr[i]);
}

int is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while(a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int stack_size(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void sort_top_b(t_stack **b, int dno_b)
{
	if (stack_size(*b) - dno_b == 2 && (*b)->data < (*b)->next->data)
		do_sb(b);
}

int sort_top_a(t_stack **a, int *dno_a, int a_size)
{
	if (a_size - *dno_a == 2)
	{
		if ((*a)->data > (*a)->next->data)
			do_sa(a);
		*dno_a += 2;
		return (1);
	}
	if (a_size - *dno_a == 1)
	{
		*dno_a += 1;
		return (1);
	}
	return (0);
}

int *init_arr(t_stack *a, int a_size)
{
	int i;
	int *arr;

	arr = (int*)malloc(sizeof(int) * a_size);
	i = 0;
	while (i < a_size && a)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	return(arr);
}

void swap(int *i, int *j)
{
	int t;

	t = *i;
	*i = *j;
	*j = t;
}

void myqsort (int **arr, int left, int right)
{
	int l;
	int r;
	int pivot;
	int t;

	l = left;
	r = right;
	pivot = (*arr)[(l + r) / 2];
	while (l <= r)
	{
		while ((*arr)[l] < pivot)
			l++;
		while ((*arr)[r] > pivot)
			r--;
		if (l <= r)
		{
			swap(&((*arr)[l]), &((*arr)[r]));
			l++;
			r--;
		}
	}
	if (left < r)
		myqsort (arr, left, r);
	if (right > l)
		myqsort (arr, l, right);
}


int get_b_mediana(t_stack *b, int b_size)
{
	int *arr;
	int mediana;

	arr = init_arr(b, b_size);
	myqsort(&arr, 0, b_size - 1);
	mediana = arr[(b_size - 1) / 2];
	free(arr);
	return (mediana);
}

int all_is_ok_on_the_top(t_stack **a, t_stack **b, int *dno_a, int dno_b)
{
	int b_size;

	b_size = stack_size(*b);
	if (b_size - dno_b == 2)
	{
		do_pa(a, b);
		do_pa(a, b);
		dno_a += 2;
		return (1);
	}
	if (b_size - dno_b == 1)
	{
		do_pa(a, b);
		dno_a += 1;
		return (1);
	}
	return (0);
}

void	throw_from_b(t_stack **a, t_stack **b, int *dno_a, int dno_b)
{
	int mediana;
	int b_size;
	int pushed_to_a;
	int pushed_down;
	t_stack *tmp;

	b_size = stack_size(*b);
	if (all_is_ok_on_the_top(a, b, dno_a, dno_b))
		return ;
	mediana = get_b_mediana(*b, b_size - dno_b);
	pushed_to_a = 0;
	pushed_down = 0;
	tmp = *b;
	while(pushed_to_a < (b_size - dno_b) / 2)
		if ((*b)->data > mediana)
			pushed_to_a += do_pa(a, b);
		else
			pushed_down += do_rb(b);
	pushed_to_a = 0;
	if (dno_b)
		while (pushed_to_a++ < pushed_down)
			do_rrb(b);
		//for (int i = 0; i < pushed_down; i++)
			//do_rrb(b);
}

int get_a_mediana(t_stack *b, int b_size)
{
	int *arr;
	int mediana;

	arr = init_arr(b, b_size);
	myqsort(&arr, 0, b_size - 1);
	mediana = arr[b_size / 2];
	free(arr);
	return (mediana);
}

void throw_from_a(t_stack **a, t_stack **b, int dno_a, int *dno_b)
{
	int mediana;
	int a_size;
	int pushed_to_b;
	int pushed_down;
	t_stack *tmp;

	*dno_b = stack_size(*b);
	a_size = stack_size(*a);
	mediana = get_a_mediana(*a, a_size - dno_a);
	pushed_to_b = 0;
	pushed_down = 0;
	tmp = *a;
	while(pushed_to_b < (a_size - dno_a) / 2)
	{
		if ((*a)->data < mediana)
			pushed_to_b += do_pb(b, a);
		else
			pushed_down += do_ra(a);
	}
	pushed_to_b = 0;
	if (dno_a)
		while (pushed_to_b++ < pushed_down)
			do_rra(a);
		//for (int i = 0; i < pushed_down; i++)
			//do_rra(a);
}

void sort(t_stack **a, t_stack **b, int dno_b)
{
	static int dno_a;
	int a_size;

	if (is_sorted(*a, *b))
	{
		//printf("|");
		return ;	
	}
	a_size = stack_size(*a);	
	sort_top_b(b, dno_b);
	if (dno_a == stack_size(*a) || sort_top_a(a, &dno_a, stack_size(*a)))
	{
		throw_from_b(a, b, &dno_a, dno_b);
		sort_top_a(a, &dno_a, stack_size(*a));
		return ;
	}
	throw_from_a(a, b, dno_a, &dno_b);
	//while(!flag)
	//	sort(a, b, dno_b);
	for (int i=1; i< 1000; i++)
		sort(a, b, dno_b);
}
int is_duplicats(t_stack *a)
{
	int *arr;
	int a_size;
	int i;

	a_size = stack_size(a);
	arr = init_arr(a, a_size);
	myqsort(&arr, 0, a_size - 1);
	i = 1;
	while (i < a_size)
	{
		if (arr[i - 1] == arr[i])
			return (0);
		i++;
	}
	return (1);
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
	is_valid = (is_valid && argc == is_valid + 1) ? is_duplicats(a) : 0;
	//print_stack(a);
	if (is_valid)
		sort(&a, &b, 0);

	print_stack(a);
	print_stack(b);

	if (!is_valid)
		write(1, "error\n", 6);
	del_two_stacks(&a, &b);
	//print_stack(a);
	return (0);
}