/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:35:58 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/19 14:41:13 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node **stack, int len)
{
	t_node	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		return (-1);
	while (tmp->next != NULL && len-- > 0)
	{
		if (*(int *)(tmp->content) < *(int *)(tmp->next->content))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_back(t_node **stack_a, t_node **stack_b, int len)
{
	while (len-- > 0)
		pa(stack_a, stack_b);
}

void	quicksort(t_node **stack_a, t_node **stack_b, int len)
{
	t_node	*pivot;
	int	i;
	int	rotation;

	if (len <= 5)
	{
		sort5(stack_a, stack_b);
		return ;
	}
	pivot = median(stack_a, len);
	i = -1;
	rotation = 0;
	while (++i < len && !(is_sorted(stack_a, len) == 0 && !*stack_b))
	{
		if (*(int *)(*stack_a)->content < *(int *)pivot->content)
			pb(stack_a, stack_b);
		else
		{
			if (i != rotation)
				ra(stack_a);
			rotation++;
		}
	}
	i = rotation;
	while (0 >= --rotation)
		if (i != rotation + 1)
			rra(stack_a);
	if (is_sorted(stack_a, len) == -1)
		quicksort(stack_a, stack_b, len - rotation);
	if (is_sorted(stack_a, len / 2) == -1) // if this area is not sorted, go into recursion
	{
		quicksort(stack_a, stack_b, len / 2);
		push_back(stack_a, stack_b, len - i);
	}
}
