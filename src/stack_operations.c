/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:51:54 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 20:24:15 by nburchha         ###   ########.fr       */
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

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	if (*stack_a == NULL)
		return ;
	*stack_b = *stack_a;
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	else
		*stack_a = NULL;
	(*stack_b)->next = tmp;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (*stack_b == NULL)
		return ;
	*stack_a = *stack_b;
	if ((*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	else
		*stack_b = NULL;
	(*stack_a)->next = tmp;
}

void	ra(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstlast(*stack)->next = tmp;
}

void	rb(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstlast(*stack)->next = tmp;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstlast(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstlast(*stack_b)->next = tmp;
}

void	rra(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rrb(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = ft_lstlast(*stack_a);
	tmp2 = *stack_a;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;

	tmp = ft_lstlast(*stack_b);
	tmp2 = *stack_b;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}
