#include "push_swap.h"

static void    swap(t_stack **head)
{
    // t_stack *tmp;

    if (!head || !(*head) || !(*head)->next)
        return ;
    // tmp = (*head)->next;
    // (*head)->next = tmp->next;
    // tmp->next->prev = *head;
    // tmp->next = *head;
    // tmp->prev = NULL;
    // *head = tmp;

    *head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void sa(t_stack **a, bool check)
{
    swap(a);
    if (check)
        write(1, "sa\n", 3);
}

void sb(t_stack **b, bool check)
{
    swap(b);
    if (check)
        write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a, false);
    sb(b, false);
    write(1, "ss\n", 3);
}
