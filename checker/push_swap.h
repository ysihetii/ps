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

int is_duplicats(t_stack *a);
long long	ft_atoi(const char *a);

void do_s(t_stack **a);
void do_ss(t_stack **a, t_stack **b);
void do_p(t_stack **a, t_stack **b);
void do_r(t_stack **a);
void do_rr(t_stack **a, t_stack **b);
void do_rra(t_stack **a);
void do_rrr(t_stack **a, t_stack **b);

#endif