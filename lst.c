#include "push_swap.h"
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

t_stack *new_node(int data)
{
	t_stack *node;

	node = (t_stack*)malloc(sizeof(t_stack));
	node->data = data;
	node->next = 0;
	return (node);
}

void push_front(t_stack **a, int data)
{
	t_stack *node;

	node = new_node(data);
	node->next = *a;
	*a = node;
}

void push_back(t_stack **a, int data)
{
	t_stack *node;

	if(!(*a))
	{
		*a = new_node(data);
		return;
	}
	node = *a;
	while (node->next)
		node = node->next;
	node->next = new_node(data);
}

void del_first(t_stack **a)
{
	t_stack *tmp;

		tmp = (t_stack*)malloc(sizeof(t_stack));
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
}

void del_stack(t_stack **a)
{
	t_stack *tmp;

	if (!*a)
		return;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void del_two_stacks(t_stack **a, t_stack **b)
{
	del_stack(a);
	del_stack(b);
}

void print_stack(t_stack *a)
{
	t_stack *q =a;

printf("\n----------------\n");
	while(q)
	{
		printf("%i\n", q->data);
		q = q->next;
	}
	printf("----------------\n");
}
