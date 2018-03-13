#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	struct s_stack *next;
	int data;
}	t_stack;


char			**ft_strsplit(char const *s, int *size);

void push_front(t_stack **a, int data);
void push_back(t_stack **a, int data);
void print_stack(t_stack *a);
void del_first(t_stack **a);
void del_two_stacks(t_stack **a, t_stack **b);
int read_stack_a(t_stack **a, int argc, char **argv);

long long	ft_atoi(const char *a);

int do_sa(t_stack **a);
int do_sb(t_stack **a);
int do_ss(t_stack **a, t_stack **b);
int do_pa(t_stack **a, t_stack **b);
int do_pb(t_stack **a, t_stack **b);
int do_ra(t_stack **a);
int do_rb(t_stack **a);
int do_rr(t_stack **a, t_stack **b);
int do_rra(t_stack **a);
int do_rrb(t_stack **a);
int do_rrr(t_stack **a, t_stack **b);

#endif