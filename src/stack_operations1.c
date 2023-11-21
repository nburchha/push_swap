/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:59 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 22:52:47 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, int print)
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
	if (print == 0)
		ft_printf("rr\n");
}

void	rra(t_node **stack, int print)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stack)->next == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (print == 0)
		ft_printf("rra\n");
}

void	rrb(t_node **stack, int print)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stack)->next == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (print == 0)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, int print)
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
	if (print == 0)
		ft_printf("rrr\n");
}
