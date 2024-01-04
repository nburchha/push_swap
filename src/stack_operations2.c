/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:15:36 by nburchha          #+#    #+#             */
/*   Updated: 2024/01/04 01:04:20 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b, int print)
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
	if (print == 0)
		ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b, int print)
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
	if (print == 0)
		ft_printf("pa\n");
}

void	ra(t_node **stack, int print)
{
	t_node	*tmp;

	if (*stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstlast_mod(*stack)->next = tmp;
	if (print == 0)
		ft_printf("ra\n");
}

void	rb(t_node **stack, int print)
{
	t_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstlast_mod(*stack)->next = tmp;
	if (print == 0)
		ft_printf("rb\n");
}
