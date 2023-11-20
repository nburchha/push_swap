/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:56:35 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 15:29:32 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

t_node	*find_biggest_element(t_node **stack)
{
	t_node	*tmp;
	t_node	*biggest;

	tmp = *stack;
	biggest = tmp;
	while (tmp != NULL)
	{
		if (tmp->index > biggest->index)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

void	push_back(t_node **stack_a, t_node **stack_b, int len)
{
	while (len > 0)
	{
		which_rotation(stack_b, find_biggest_element(stack_b));
		pa(stack_a, stack_b);
		len--;
	}
}

void	k_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int range;

	i = 0;
	range = ft_sqrt(ft_lstsize(*stack_a)) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	push_back(stack_a, stack_b, ft_lstsize(*stack_b));
}
