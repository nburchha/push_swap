/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:56:35 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/21 17:46:57 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sqrt(int nb)
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
		which_rotation(stack_b, find_biggest_element(stack_b), 1);
		pa(stack_a, stack_b, 0);
		len--;
	}
}

void	k_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(ft_lstsize(*stack_a)) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else
			ra(stack_a, 0);
	}
	push_back(stack_a, stack_b, ft_lstsize(*stack_b));
}
