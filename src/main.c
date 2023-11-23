/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:19 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 19:44:56 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		ft_printf("%d ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 && (*stack_a)->index > \
	(*stack_a)->next->index)
		sa(stack_a, 1);
	else if (ft_lstsize(*stack_a) <= 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort5(stack_a, stack_b);
	else
	{
		k_sort(stack_a, stack_b);
		push_back(stack_a, stack_b, ft_lstsize(*stack_b));
	}
}

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
		return (0);
	init_stack(&argv[1], stack_a);
	if (*stack_a == NULL)
		return (write(2, "Error\n", 6), free(stack_a), free(stack_b), 1);
	sorted_index(stack_a);
	if (ft_lstsize(*stack_a) > 2 && is_sorted(stack_a, stack_b) == 0)
		sort(stack_a, stack_b);
	return (free(stack_b), ft_lstclear(stack_a, &free), free(stack_a), 0);
}
