/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:52:27 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 15:43:45 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_exit(t_node **stack_a, t_node **stack_b, char **split)
{
	if (split != NULL)
		free_split(split);
	if (stack_a != NULL)
		ft_lstclear(stack_a, &free);
	if (stack_b != NULL)
		ft_lstclear(stack_b, &free);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	if (split == NULL)
		return ;
	while (split[++i])
		free(split[i]);
	free(split);
}
