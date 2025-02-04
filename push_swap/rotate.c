#include "push_swap.h"

static void    rotate(t_stack **head)
{
    t_stack *tmp;

    if (!head | !(*head) | !(*head)->next)
        return ;
    tmp = lstlast(*head);
    tmp->next = *head;
    (*head)->prev = tmp;
    (*head)->next->prev = NULL;
    *head = (*head)->next;
    tmp->next->next = NULL;
}

void ra(t_stack **a, bool check)
{
    rotate(a);
    if (check)
        write(1, "ra\n", 3);
}

void rb(t_stack **b, bool check)
{
    rotate(b);
    if (check)
        write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a, false);
    rb(b, false);
    write(1, "rr\n", 3);
}
