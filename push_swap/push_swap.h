#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
    int     index;
    int     value;
    int     price;
    bool    medlin;
    bool    cheapest;
    struct s_stack *target_node;
    struct s_stack *next;
    struct s_stack *prev;
}t_stack;

char    **ft_validate_input(int ac, char **av);
t_stack *ft_list(char **sp);
t_stack	*lstlast(t_stack *head);
//operations
// void    swap(t_stack **head);
void    sa(t_stack **a, bool check);
void    sb(t_stack **b, bool check);
void    ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void    ra(t_stack **a, bool check);
void    rb(t_stack **b, bool check);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, bool check);
void    rrb(t_stack **b, bool check);
void    rrr(t_stack **a, t_stack **b);
//big value de node
t_stack *biggest(t_stack *head);
t_stack *smaller(t_stack *head);
void    sort_3(t_stack **head);
int     size_stack(t_stack *head);
//
void    small_stack(t_stack **a, t_stack **b);
//
void    big_stack(t_stack **a, t_stack **b);
#endif
