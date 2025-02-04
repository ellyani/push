/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:05:02 by sellyani          #+#    #+#             */
/*   Updated: 2024/11/13 17:48:20 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft(long *i, long *sign, char s)
{
	if (s == '-' || s == '+')
	{
		if (s == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;
	long	sg;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	ft(&i, &sign, str[i]);
	while (str[i] && ft_isdigit(str[i]))
	{
		sg = result;
		result = (result * 10) + (str[i] - 48);
		if ((sg != (result / 10) && sign == 1))
			return (-1);
		if ((sg != (result / 10) && sign == -1))
			return (0);
		i++;
	}
	return (result * sign);
}
