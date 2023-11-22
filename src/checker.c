/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:39:39 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/21 20:23:30 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_whole(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b != NULL)
		return (-1);
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_bool	operations(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
			return (sa(*stack_a, 1), true);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		return (sb(*stack_b, 1), true);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		return (ss(*stack_a, *stack_b, 1), true);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		return (pa(stack_a, stack_b, 1), true);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		return (pb(stack_a, stack_b, 1), true);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		return (ra(stack_a, 1), true);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		return (rb(stack_b, 1), true);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		return (rr(stack_a, stack_b, 1), true);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		return (rra(stack_a, 1), true);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		return (rrb(stack_b, 1), true);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		return (rrr(stack_a, stack_b, 1), true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	*line;

	if (argc <= 2)
		return (1);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	*stack_a = allocate_stack_a(&argv[1]);
	if (*stack_a == NULL)
		return (ft_printf("jojojo\n"), free(stack_a), free(stack_b), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!operations(line, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			return (free(line), free(stack_b), ft_lstclear(stack_a, &free), free(stack_a), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_whole(stack_a, stack_b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(stack_b), ft_lstclear(stack_a, &free), free(stack_a), 0);
}
