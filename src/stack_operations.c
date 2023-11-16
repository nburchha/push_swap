/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:51:54 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 16:07:14 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node	*stack)
{
	void	*tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_node	*stack)
{
	void	*tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_node *stack_a, t_node *stack_b)
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
	ft_printf("ss\n");
}

void	pa(t_node *stack_a, t_node *stack_b)
{
	if (!stack_b || stack_b->content == NULL)
		return ;
	ft_lstadd_front(&stack_a, stack_b);
	stack_b = stack_b->next;
}

void	pb(t_node *stack_b, t_node *stack_a)
{
	if (!(stack_a))//  || (*stack_a)->content == NULL)
		return ;
	// ft_printf("stack_b: %d\n", (int *)stack_b->content);
	ft_lstadd_front(&stack_b, stack_a);
	ft_printf("stack_b: %d\n", stack_b->content);
	stack_a = stack_a->next;
}
