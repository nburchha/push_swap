/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:12 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/18 19:16:33 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP

# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <stddef.h>
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
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);

void	test_functions(t_node **stack_a, t_node **stack_b);
void	print_stack(const char *stack_name, t_node *stack);
// void	insertion_sort(t_node **stack_a, t_node **stack_b);

void	sort3(t_node **stack_a);
void	sort5(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **stack, int len);
int		find_element(t_node **stack_a, int num);
t_node	*median(t_node **stack, int len);
void	quicksort(t_node **stack_a, t_node **stack_b, int len);

#endif