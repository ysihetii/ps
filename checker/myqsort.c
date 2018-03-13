#include "push_swap.h"
#include <stdlib.h>



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
