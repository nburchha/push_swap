/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:21:07 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/26 17:45:48 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*init_content(int num)
{
	int	*num_p;

	num_p = (int *)malloc(sizeof(int));
	if (num_p == NULL)
		return (NULL);
	*num_p = num;
	return ((void *)num_p);
}

void	init_stack2(t_node **stack_a, char **split_str, int j)
{
	while (split_str[++j])
	{
		if (check_input(split_str[j]) == -1)
			free_exit(stack_a, NULL, split_str);
		ft_lstadd_back(stack_a, \
		ft_lstnew(init_content(ft_atoi(split_str[j]))));
		if (ft_lstlast(*stack_a) == NULL)
			free_exit(stack_a, NULL, split_str);
	}
}

void	init_stack(char **input, t_node **stack_a)
{
	int		i;
	int		j;
	char	**split_str;

	i = -1;
	while (input[++i])
	{
		j = -1;
		split_str = ft_split(input[i], ' ');
		if (split_str == NULL)
			free_exit(stack_a, NULL, NULL);
		if (i == 0)
		{
			if (check_input(split_str[++j]) == -1)
				free_exit(stack_a, NULL, split_str);
			ft_lstadd_back(stack_a, \
			ft_lstnew(init_content(ft_atoi(split_str[j]))));
			if (ft_lstlast(*stack_a) == NULL)
				free_exit(stack_a, NULL, split_str);
		}
		init_stack2(stack_a, split_str, j);
		free_split(split_str);
	}
	if (check_double(*stack_a) == -1)
		free_exit(stack_a, NULL, NULL);
}
