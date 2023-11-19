/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:19:37 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/19 16:29:21 by nburchha         ###   ########.fr       */
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
		if (*(int *)tmp->content < *(int *)smallest->content)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	which_rotation(t_node **stack_a, t_node *node_to_rotate)
{
	int		r;
	int		rr;
	t_node	*tmp;

	r = 0;
	rr = 0;
	tmp = *stack_a;
	while (tmp != NULL && tmp != node_to_rotate)
	{
		r++;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		rr++;
		tmp = tmp->next;
	}
	if (r < rr)
		while (r-- > 0)
			ra(stack_a);
	else
		while (rr-- > 0)
			rra(stack_a);
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
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
