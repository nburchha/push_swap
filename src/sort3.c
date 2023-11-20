/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:50:01 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 13:48:46 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort3(t_node **stack)
{
	if ((*stack)->next->next->index < (*stack)->index || (*stack)->next->next->index < (*stack)->next->index)
	{
		if ((*stack)->index > (*stack)->next->index)
			ra(stack);
		else
			rra(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
			sa(*stack);
}


