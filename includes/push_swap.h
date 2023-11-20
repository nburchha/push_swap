/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:12 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 14:19:01 by nburchha         ###   ########.fr       */
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
	void		*content;
	int			index;
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

void	sort3(t_node **stack);
void	sort5(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **stack, int len);
t_node	*median(t_node **stack, int len);
void	quicksort(t_node **stack_a, t_node **stack_b, int len);

void	k_sort(t_node **stack_a, t_node **stack_b);
void	sorted_index(t_node **stack_a);
void	which_rotation(t_node **stack_a, t_node *node_to_rotate);
t_node	*find_element(t_node **stack, int index);
void	push_back(t_node **stack_a, t_node **stack_b, int len);
// t_node	*find_biggest_element(t_node **stack_a);

#endif