/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:39:39 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 23:45:10 by nburchha         ###   ########.fr       */
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

void	operations(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
			sa(*stack_a, 1);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(*stack_b, 1);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(*stack_a, *stack_b, 1);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(stack_a, stack_b, 1);
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
		return (free(stack_a), free(stack_b), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		operations(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_whole(stack_a, stack_b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(stack_b), ft_lstclear(stack_a, &free), free(stack_a), 0);
}
