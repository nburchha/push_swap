/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:19:37 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/19 14:07:21 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort5a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->next->next->next != NULL)
	{
		if (find_element(stack_a, *(int *)(*stack_a)->content) == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (find_element(stack_b, *(int *)(*stack_b)->content) == 1)
		sa(*stack_b);
	sort3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}

void	sort5b(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->next->next->next != NULL)
	{
		if (find_element(stack_a, *(int *)(*stack_a)->content) == -1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (find_element(stack_b, *(int *)(*stack_b)->content) == -1)
		sa(*stack_b);
	sort3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL)
		return ;
	if (find_element(stack_a, *(int *)(*stack_a)->content) == 1)
		sort5a(stack_a, stack_b);
	else
		sort5b(stack_a, stack_b);
}
