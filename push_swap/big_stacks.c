#include "push_swap.h"

void target_node(t_stack *a, t_stack *b)
{
    t_stack *target_node;
    long    top_index;
    t_stack *node_a;

    while (b)
    {
        top_index = LONG_MAX;
        node_a = a;
        while (node_a)
        {
            if (node_a->value > b->value && node_a->value < top_index)
            {
                top_index = node_a->value;
                target_node =  node_a;
            }
            node_a = node_a->next; 
        }
        if (top_index == LONG_MAX)
            b->target_node = smaller(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void sort_index(t_stack *head)
{
    int     i;
    int     len_head;

    if (!head)
        return ;
    len_head = size_stack(head);
    i = 0;
    while (head)
    {
        head->index = i;
        if (head->index <= (len_head / 2))
            head->medlin = true;
        else
            head->medlin = false;
        head = head->next;
        i++;
    }
}

void    price_node(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = size_stack(a);
    len_b = size_stack(b);
    while (b)
    {
        b->price = b->index;
        if (!(b->medlin))
            b->price = len_b - b->index;
        if (b->target_node->medlin)
            b->price += b->target_node->index;
        else
            b->price += len_a - b->target_node->index;
        b = b->next;
    }
}

void    cheapest_node(t_stack *b)
{
    long cheap;
    t_stack *node_cheap;

    if (!b)
        return ;
    cheap = LONG_MAX;
    while (b)
    {
        if (b->price < cheap)
        {
            cheap = b->price;
            node_cheap = b;
        }
        b = b->next;
    }
    node_cheap->cheapest = true;
}

void    init_stack(t_stack **a, t_stack **b)
{
    sort_index(*a);
    sort_index(*b);
    target_node(*a, *b);
    price_node(*a, *b);
    cheapest_node(*b);
}

// ------------------------------------------------------------------

t_stack *get_cheapest_node(t_stack *b)
{
    t_stack *cheap_node;

    if (!b)
        return NULL;
    cheap_node = b;
    while (b)
    {
        if (b->cheapest)
            cheap_node = b;
        b = b->next;
    }
    return (cheap_node);
}

static void double_rotate(t_stack **a, t_stack **b, t_stack *cheap_node)
{
    while (*a != cheap_node->target_node && *b != cheap_node)
        rr(a, b);
    sort_index(*a);
    sort_index(*b);
}

static void reverse_double_rotate(t_stack **a, t_stack **b, t_stack *cheap_node)
{
    while (*a != cheap_node->target_node && *b != cheap_node)
        rrr(a, b);
    sort_index(*a);
    sort_index(*b);
}

void    last_rotate(t_stack **head, t_stack *top_node, char name)
{
    while (*head != top_node)
    {
        if (name == 'a')
        {
            if (top_node->medlin)
                ra(head, true);
            else
                rra(head, true);
        }
        else if (name == 'b')
        {
            if (top_node->medlin)
                rb(head, true);
            else
                rrb(head, true);
        }
    }
}

void    move_node(t_stack **a, t_stack **b)
{
    t_stack *cheap_node;

    cheap_node = get_cheapest_node(*b);
    if (cheap_node->medlin && cheap_node->target_node->medlin)
        double_rotate(a, b, cheap_node);
    else if (!(cheap_node->medlin) && !(cheap_node->target_node->medlin))
        reverse_double_rotate(a, b, cheap_node);
    last_rotate(b, cheap_node, 'b');
    last_rotate(a, cheap_node->target_node , 'a');
    pa(a, b);
}

// ------------------------------------------------------------------

void  big_stack(t_stack **a, t_stack **b)
{
    t_stack *small_node;

    while (size_stack(*a) > 3)
        pb(b, a);
    sort_3(a);
    while (*b)
    {
        init_stack(a, b);
        move_node(a, b);
    }
    sort_index(*a);
    small_node = smaller(*a);
    if (small_node->medlin)
        while (*a != small_node)
            ra(a, true);
    else
        while (*a != small_node)
            rra(a, true);
}
