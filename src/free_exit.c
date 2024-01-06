/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:52:27 by nburchha          #+#    #+#             */
/*   Updated: 2024/01/06 14:29:59 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_exit(t_node **stack_a, t_node **stack_b, char **split)
{
	if (split != NULL)
		free_split(split);
	if (stack_a != NULL)
		ft_lstclear_mod(stack_a);
	if (stack_b != NULL)
		ft_lstclear_mod(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
