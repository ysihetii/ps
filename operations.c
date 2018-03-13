#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int do_sa(t_stack **a)
{
	int tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int do_sb(t_stack **a)
{
	int tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int do_ss(t_stack **a, t_stack **b)
{
	return (do_sa(a) + do_sb(b));
}

int do_pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		push_front(a, (*b)->data);
		del_first(b);
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}
int do_pb(t_stack **a, t_stack **b)
{
	if (*b)
	{
		push_front(a, (*b)->data);
		del_first(b);
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

int do_ra(t_stack **a)
{
	if (*a && (*a)->next)
	{
		push_back(a, (*a)->data);
		del_first(a);
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int do_rb(t_stack **a)
{
	if (*a && (*a)->next)
	{
		push_back(a, (*a)->data);
		del_first(a);
		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int do_rr(t_stack **a, t_stack **b)
{
	return (do_ra(a) + do_rb(b));
}

int do_rra(t_stack **a)
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
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}
int do_rrb(t_stack **a)
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
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int do_rrr(t_stack **a, t_stack **b)
{
	return (do_rra(a) + do_rrb(b));
}


