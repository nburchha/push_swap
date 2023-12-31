/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:02:11 by nburchha          #+#    #+#             */
/*   Updated: 2024/01/04 01:01:25 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	*fill_array(t_node **stack, int len)
{
	int		*array;
	int		i;
	t_node	*temp;

	i = -1;
	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (++i < len && temp)
	{
		array[i] = *(int *)temp->content;
		temp = temp->next;
	}
	return (array);
}

void	bubble_sort(int array[], int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	assign_index(int *array, int len, int value)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (array[i] == value)
			return (i);
	}
	return (-1);
}

void	sorted_index(t_node **stack_a)
{
	int		*array;
	int		i;
	int		len;
	t_node	*tmp;

	len = ft_lstsize_mod(*stack_a);
	array = fill_array(stack_a, len);
	if (!array)
		return ;
	bubble_sort(array, len);
	i = -1;
	tmp = *stack_a;
	while (++i < len && tmp)
	{
		tmp->index = assign_index(array, len, *(int *)tmp->content);
		tmp = tmp->next;
	}
	free(array);
}
