/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:51:54 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/21 00:56:15 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node *stack, int print)
{
	t_node	*tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	if (print == 0)
		ft_printf("sa\n");
}

void	sb(t_node	*stack, int print)
{
	t_node	*tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	if (print == 0)
		ft_printf("sb\n");
}

void	ss(t_node *stack_a, t_node *stack_b, int print)
{
	void	*tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
	if (stack_b && stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
	}
	if (print == 0)
		ft_printf("ss\n");
}
