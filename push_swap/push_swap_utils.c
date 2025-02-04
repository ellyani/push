#include "push_swap.h"

t_stack *smaller(t_stack *head)
{
    t_stack *small;

    if (!head)
        return NULL;
    small = head;
    while (head)
    {
        if (head->value < small->value)
            small = head;
        head = head->next;
    }
    return (small);
}

t_stack *biggest(t_stack *head)
{
    t_stack *big;

    if (!head)
        return NULL;
    big = head;
    while (head)
    {
        if (head->value > big->value)
            big = head;
        head = head->next;
    }
    return (big);
}
// ./push_swap "34 576 97" -6 " 9 99" 0

int size_stack(t_stack *head)
{
    int size;

    size = 0;
    if (!head)
        return (0);
    while (head)
    {
        size++;
        head = head->next;
    }
    return (size);
}