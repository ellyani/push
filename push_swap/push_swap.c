#include "push_swap.h"
#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    char    **sp;
    t_stack *b;
    
    if (ac > 1)
    {
        sp = ft_validate_input(ac, av);
        if (!sp)
            return (0);
        a = ft_list(sp);
        b = NULL;
        if (size_stack(a) <= 4)
            small_stack(&a, &b);
        else
            big_stack(&a,&b);
        (void)b;
        // sort_3(&a);
        // t_stack *tmp = a;
        // while (tmp->next)
        //     tmp = tmp->next;
        // while (tmp)

        // {
        //     printf("%d | %d\n", tmp->index, tmp->value);
        //     tmp = tmp->prev;
        // }
        // while (tmp)
        // {
        //     printf("%d\n", tmp->value);
        //     tmp = tmp->next;
        // }
        // printf("============\n");
        // tmp = b;
        // while (tmp)
        // {
        //     printf("%d\n", tmp->value);
        //     tmp = tmp->next;
        // }
        // (void)a;
    }
}
