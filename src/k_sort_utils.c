/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:54:23 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 00:48:04 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_element(t_node **stack, int index)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// t_node	*find_biggest_element(t_node **stack_a)
// {
// 	t_node	*tmp;
// 	t_node	*biggest;

// 	tmp = *stack_a;
// 	biggest = tmp;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->index > biggest->index)
// 			biggest = tmp;
// 		tmp = tmp->next;
// 	}
// 	ft_printf("biggest = %p\n", biggest);
// 	return (biggest);
// }
