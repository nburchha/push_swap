/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:12 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 15:57:55 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP

# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libftprintf/ft_printf.h"

# ifndef S_NODE
#  define S_NODE
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;
# endif

int	main(int argc, char **argv);
t_node	*allocate_stack_a(char **input);
void	sa(t_node	*stack);
void	sb(t_node	*stack);
void	ss(t_node *stack_a, t_node *stack_b);
void	pa(t_node *stack_a, t_node *stack_b);
void	pb(t_node *stack_b, t_node *stack_a);

#endif