/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:50:01 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/18 18:35:03 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/// @return -1 if given num is the first position in the stack, 0 if somewhere in the middle and 1 if its at the end
int	find_element(t_node **stack_a, int num)
{
	t_node	*tmp;
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	if ((*stack_a)->next == NULL)
		return (1);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (num > *(int *)tmp->content)
			flag1 = 1;
		if (num < *(int *)tmp->content)
			flag2 = 1;
		tmp = tmp->next;
	}
	if (flag1 == 0 && flag2 == 1)
		return (-1);
	if (flag1 == 1 && flag2 == 0)
		return (1);
	return (0);
}

void	sort3(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (find_element(stack_a, *(int *)ft_lstlast(tmp)->content) != 1) //if the last item is not the highest num
	{
		if (find_element(stack_a, *(int *)tmp->content) != 1)			//if the first num is not the highest num
			sa(*stack_a);
		ra(stack_a);
	}
	if (find_element(stack_a, *(int *)(*stack_a)->content) != -1)
		sa(*stack_a);
	// print_stack("stack", *stack_a);
}


