/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:35:58 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/19 18:22:22 by nburchha         ###   ########.fr       */
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
	int	less_than_pivot;

	if (len <= 5)
	{
		sort5(stack_a, stack_b);
		return ;
	}
	pivot = median(stack_a, len);
	i = -1;
	less_than_pivot = 0;
	while (++i < len)// && !(is_sorted(stack_a, len) == 0 && !*stack_b) && *stack_a)
	{
		if (*(int *)(*stack_a)->content < *(int *)pivot->content)
		{
			pb(stack_a, stack_b);
			less_than_pivot++;
		}
		else
			ra(stack_a);
	}
	i = less_than_pivot;
	while (0 >= --i)
		pa(stack_a, stack_b);
	quicksort(stack_b, stack_a, less_than_pivot);
	push_back(stack_b, stack_a, less_than_pivot);
	quicksort(stack_a, stack_b, len - less_than_pivot - 1);
	push_back(stack_b, stack_a, len - less_than_pivot - 1);
}
