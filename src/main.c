/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:19 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 19:34:44 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc == 1)
		return (1);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (stack_a == NULL || stack_b == NULL)
		return (1);
	*stack_a = allocate_stack_a(&argv[1]);
	if (*stack_a == NULL)
		return (1);
	if (argc > 2)
		test_functions(stack_a, stack_b);
	// return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free), 0);
}
