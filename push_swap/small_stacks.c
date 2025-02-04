#include "push_swap.h"

void    sort_3(t_stack **head)
{
    t_stack *big;

    big = biggest(*head);
    if (*head == big)
        ra(head, true);
    else if ((*head)->next == big)
        rra(head, true);
    if ((*head)->value > (*head)->next->value)
        sa(head, true);
}

static void    sort_4(t_stack **a, t_stack **b)
{
    int     indx;
    t_stack *tmp;

    tmp = *a;
    while (tmp)
    {
        if (tmp == smaller(*a))
            indx = tmp->index;
        tmp = tmp->next;
    }
    if (indx == 1)
        ra(a, true);
    else if (indx == 2)
    {
        ra(a, true);
        ra(a, true);
    }
    else if (indx == 3)
        rra(a, true);
    pb(b, a);
    sort_3(a);
    pa(a, b);
}

void small_stack(t_stack **a, t_stack **b)
{
    if (size_stack(*a) == 2)
    {
        if ((*a)->value > (*a)->next->value)
            sa(a, true);
    }
    else if (size_stack(*a) == 3)
        sort_3(a);
    else if (size_stack(*a) == 4)
        sort_4(a, b);
}
