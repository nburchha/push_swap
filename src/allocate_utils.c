/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:53:45 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 19:53:46 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (*(int *)tmp->content == *(int *)tmp2->content)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_input(const char *str)
{
	int	i;

	i = -1;
	if ((ft_strlen(str) > 10 && str[0] != '-') || \
		(ft_strlen(str) > 11 && str[0] == '-'))
		return (-1);
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	return (0);
}
