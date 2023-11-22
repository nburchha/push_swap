/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:21:07 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/22 23:23:57 by nburchha         ###   ########.fr       */
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
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && str[i + 1] == '-')
			return (-1);
		if (str[i] == ' ' || str[i] == '-')
		{
			if (str[i] == '-')
				j++;
			if (i - j >= 10)
				return (-1);
			i++;
			j = i;
		}
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
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

void	allocate_stack_a(char **input, t_node **stack_a)
{
	int		i;
	int		j;
	char **splitted_strings;

	i = -1;
	while (input[++i])
	{
		j = -1;
		splitted_strings = ft_split(input[i], ' ');
		if (splitted_strings == NULL)
			free_exit(stack_a, NULL, splitted_strings);
		if (i == 0)
		{
			j++;
			*stack_a = ft_lstnew(allocate_content(ft_atoi(splitted_strings[j])));
			if (*stack_a == NULL)
				free_exit(NULL, NULL, splitted_strings);
		}
		while (splitted_strings[++j])
		{
			if (check_input(splitted_strings[j]) == -1)
				free_exit(stack_a, NULL, splitted_strings);
			ft_lstadd_back(stack_a, \
			ft_lstnew(allocate_content(ft_atoi(splitted_strings[j]))));
			if (ft_lstlast(*stack_a) == NULL)
				free_exit(stack_a, NULL, splitted_strings);
		}
		free_split(splitted_strings);
	}
	if (check_double(*stack_a) == -1)
		free_exit(stack_a, NULL, splitted_strings);
}

void	free_exit(t_node **stack_a, t_node **stack_b, char **split)
{
	if (split != NULL)
		free_split(split);
	ft_lstclear(stack_a, &free);
	ft_lstclear(stack_b, &free);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}