/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:19 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 16:12:54 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc == 1)
		return (1);
	stack_a = malloc(sizeof(t_node *));
	*stack_a = allocate_stack_a(&argv[1]);
	stack_b = malloc(sizeof(t_node *));
	if (stack_b == NULL)
		return (1);
	if (*stack_a == NULL)
		return (1);
	if (argc > 2)
		pb(*stack_a, *stack_b);
	ft_printf("stack_a: %p\n", *stack_a);
	ft_printf("stack_b: %p\n", *stack_b);
	ft_printf("stack_a: %d\n", *((int *)(*stack_a)->content));
	ft_printf("stack_a: %d\n", *((int *)(*stack_a)->next->content));
	// ft_printf("top of stack_b%d\n", *((int *)stack_b->content));
	// return (ft_lstclear(&stack_a, free), ft_lstclear(&stack_b, free), 0);
}
