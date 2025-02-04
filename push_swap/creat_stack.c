#include "push_swap.h"

//sp --> sp[0] = 34 , sp[1] = 576 , sp[2] = 97 , sp[3] = -6

t_stack	*lstnew(char *content, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = ft_atoi(content);
    new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*lstlast(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	lstadd_back(t_stack **head, t_stack *new_node)
{
	if (!head || new_node == NULL)
		return ;
	t_stack *tmp = lstlast (*head);
	if (*head != NULL)
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
	else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
}

t_stack *ft_list(char **sp)
{
    t_stack *a;
    int i;

    i = 0;
    a = NULL;
    while (sp[i])
    {
        lstadd_back(&a, lstnew(sp[i], i));
        i++;
    }
    return (a);
}
