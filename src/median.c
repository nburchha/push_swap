/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:04:09 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/18 22:01:01 by nburchha         ###   ########.fr       */
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
	int	*array;
	int	i;
	t_node *temp;

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

t_node *find_node(t_node **stack, int value)
{
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		if (*(int *)temp->content == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/// @param len how many nodes to count
/// @return node with the median content value
t_node	*median(t_node **stack, int len)
{
	int		*array;
	int		i;
	int		temp;

	array = fill_array(stack, len);
	if (!array)
		return (NULL);
	i = 1;
	while (array && is_sorted_array(array, len) == -1)
	{
		if (array[i] < array[i - 1])
		{
			temp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = temp;
		}
		i++;
		if (i >= len)
			i = 1;
	}
	if (array)
		temp = array[len / 2];
	free (array);
	return (find_node(stack , temp));
}
