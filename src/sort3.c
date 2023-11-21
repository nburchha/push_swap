/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:50:01 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/21 00:45:50 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (*stack_b != NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort3(t_node **stack)
{
	if ((*stack)->next->next->index < (*stack)->index || \
	(*stack)->next->next->index < (*stack)->next->index)
	{
		if ((*stack)->index > (*stack)->next->index)
			ra(stack, 0);
		else
			rra(stack, 0);
	}
	if ((*stack)->index > (*stack)->next->index)
		sa(*stack, 0);
}
