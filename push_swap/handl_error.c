#include "push_swap.h"

char **split_arg(int ac, char **av)
{
    char *line;
    char *fr_line;
    char *fr_line2;
    char **sp;
    int i;

    i = 1;
    line = ft_strdup("");
    while (i < ac)
    {   fr_line = line;
        fr_line2 = ft_strjoin(av[i]," ");
        line = ft_strjoin(fr_line, fr_line2);
        free(fr_line);
        free(fr_line2);
        i++;
    }
    sp = ft_split(line, ' ');
    free(line);
    return (sp);
}
int ft_is_number(char *str)
{
    int i;

    i = 0;
    if((str[i] == '-' || str[i] == '+') && str[i + 1])
        i++;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char    **ft_validate_input(int ac, char **av)
{
    int i;
    int j;
    int num;

    i = 0;
    char **sp = split_arg(ac, av);
    if (!sp || !(*sp))
        return (ft_putendl_fd("error", 2), NULL);
    while (sp[i])
    {
        if (!ft_is_number(sp[i]))
            return (ft_putendl_fd("error : invalid input", 2), NULL);
        num = ft_atoi(sp[i]);
        j = i + 1;
        while (sp[j])
        {
            if (num == ft_atoi(sp[j]))
                return (ft_putendl_fd("error : duplicate numbers.", 2), NULL);
            j++;
        }
        i++;
    }
    return (sp);
}
