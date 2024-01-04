/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:14:59 by nburchha          #+#    #+#             */
/*   Updated: 2024/01/04 01:04:05 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*tmp;

	if (*stack_a != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstlast_mod(*stack_a)->next = tmp;
	}
	if (*stack_b != NULL)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstlast_mod(*stack_b)->next = tmp;
	}
	if (print == 0)
		ft_printf("rr\n");
}

void	rra(t_node **stack, int print)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = ft_lstlast_mod(*stack);
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

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = ft_lstlast_mod(*stack);
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

	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		tmp = ft_lstlast_mod(*stack_a);
		tmp2 = *stack_a;
		while (tmp2->next->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		tmp = ft_lstlast_mod(*stack_b);
		tmp2 = *stack_b;
		while (tmp2->next->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	if (print == 0)
		ft_printf("rrr\n");
}
