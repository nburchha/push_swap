/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:19:37 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 15:23:04 by nburchha         ###   ########.fr       */
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
	ft_printf("smallest = %p\n", smallest);
	return (smallest);
}

void	which_rotation(t_node **stack_a, t_node *node_to_rotate)
{
	int		r;
	int		rr;
	t_node	*tmp;

	if (node_to_rotate == NULL)
		return ;
	r = 0;
	tmp = *stack_a;
	while (tmp != NULL && tmp != node_to_rotate)
	{
		r++;
		tmp = tmp->next;
	}
	rr = (ft_lstsize(*stack_a) + 3) - r;
	if (r <= rr)
		while (*stack_a != node_to_rotate)
			rb(stack_a);
	else
		while (*stack_a != node_to_rotate)
			rrb(stack_a);
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
	{
		sort3(stack_a);
		return ;
	}
	which_rotation(stack_a, find_smallest_element(stack_a));
	pb(stack_a, stack_b);
	which_rotation(stack_a, find_smallest_element(stack_a));
	pb(stack_a, stack_b);
	sort3(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(*stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
