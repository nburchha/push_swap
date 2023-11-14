/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:19 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 21:08:28 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = allocate_stack_a(&argv[1]);
	if (stack_a == NULL)
		return (1);
	if (argc > 2)
		pb(stack_b, &stack_a);
	ft_printf("top of stack_a%d\n", *((int *)stack_a->content));
	ft_printf("top of stack_b%d\n", *((int *)stack_b->content));
	return (ft_lstclear(&stack_a, free), ft_lstclear(&stack_b, free), 0);
}
