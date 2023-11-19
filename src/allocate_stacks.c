/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:21:07 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/19 20:01:59 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (*(int *)tmp->content == *(int *)tmp2->content)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_input(const char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	if (i > 10 && str[i - 1] - '0' > 7 && str[0] != '-')
		return (-1);
	if (i > 11 && str[0] == '-' && str[i - 1] - '0' > 8)
		return (-1);
	return (0);
}

void	*allocate_content(int num)
{
	int	*num_p;

	num_p = (int *)malloc(sizeof(int));
	if (num_p == NULL)
		return (NULL);
	*num_p = num;
	return ((void *)num_p);
}

t_node	*allocate_stack_a(char **input)
{
	t_node	*stack_a;
	t_node	*tmp;
	int	i;

	i = 0;
	if (check_input(input[i]) == -1)
			return (write(2, "Error!\n", 7), NULL);
	stack_a = ft_lstnew(allocate_content(ft_atoi(input[i])));
	if (stack_a == NULL)
		return (ft_lstclear(&stack_a, free), write(2, "Error!\n", 7), NULL);
	tmp = stack_a;
	while (input[++i])
	{
		if (check_input(input[i]) == -1)
			return (ft_lstclear(&stack_a, free), write(2, "Error!\n", 7), NULL);
		ft_lstadd_back(&stack_a, ft_lstnew(allocate_content(ft_atoi(input[i]))));
		if (tmp->next == NULL)
			return (ft_lstclear(&stack_a, free), write(2, "Error!\n", 7), NULL);
		tmp = tmp->next;
	}
	if (check_double(stack_a) == -1)
		return (write(2, "Error!\n", 7), NULL);
	sorted_index(&stack_a);
	return (stack_a);
}
