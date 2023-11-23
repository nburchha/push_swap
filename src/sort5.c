/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:19:37 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 19:09:47 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_smallest_element(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*smallest;

	tmp = *stack_a;
	smallest = tmp;
	while (tmp != NULL)
	{
		if (tmp->index < smallest->index)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	r_util(t_node *rotate_to, t_node **stack, int a_or_b, int r_or_rr)
{
	if (r_or_rr <= 0)
	{
		while (*stack != rotate_to)
		{
			if (a_or_b == 0)
				ra(stack, 0);
			else
				rb(stack, 0);
		}
	}
	else
	{
		while (*stack != rotate_to)
		{
			if (a_or_b == 0)
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	which_rotation(t_node **stack_a, t_node *rotate_to, int i)
{
	int		r;
	int		rr;
	t_node	*tmp;

	if (rotate_to == NULL)
		return ;
	r = -1;
	tmp = *stack_a;
	while (tmp != NULL && tmp != rotate_to && ++r >= 0)
		tmp = tmp->next;
	rr = (ft_lstsize(*stack_a) + 3) - r;
	r_util(rotate_to, stack_a, i, r - rr);
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
	{
		sort3(stack_a);
		return ;
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		which_rotation(stack_a, find_smallest_element(stack_a), 0);
		pb(stack_a, stack_b, 0);
	}
	sort3(stack_a);
	if ((*stack_b)->next != NULL && (*stack_b)->index < \
	(*stack_b)->next->index)
		sb(stack_b, 0);
	pa(stack_a, stack_b, 0);
	if (ft_lstsize(*stack_b) == 1)
		pa(stack_a, stack_b, 0);
}
