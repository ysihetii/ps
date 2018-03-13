#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void do_s(t_stack **a)
{
	int tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
	}
}

void do_ss(t_stack **a, t_stack **b)
{
	do_s(a);
	do_s(b);
}

void do_p(t_stack **a, t_stack **b)
{
	if (*b)
	{
		push_front(a, (*b)->data);
		del_first(b);
	}
}

void do_r(t_stack **a)
{
	if (*a && (*a)->next)
	{
		push_back(a, (*a)->data);
		del_first(a);
	}
}

void do_rr(t_stack **a, t_stack **b)
{
	do_r(a);
	do_r(b);
}

void do_rra(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		push_front(a, tmp->next->data);
		free(tmp->next);
		tmp->next = 0;
	}
}

void do_rrr(t_stack **a, t_stack **b)
{
	do_rra(a);
	do_rra(b);
}


