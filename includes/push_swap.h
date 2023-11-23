/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:12 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 19:09:01 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"

# ifndef S_NODE
#  define S_NODE

typedef struct s_node
{
	void			*content;
	int				index;
	struct s_node	*next;
}					t_node;
# endif

typedef enum e_bool{false, true}	t_bool;

void	init_stack(char **input, t_node **stack_a);
void	*init_content(int num);
int		check_input(const char *str);
int		check_double(t_node *stack);

void	free_exit(t_node **stack_a, t_node **stack_b, char **split);
void	free_split(char **split);

void	sa(t_node	**stack, int print);
void	sb(t_node	**stack, int print);
void	ss(t_node **stack_a, t_node **stack_b, int print);
void	pa(t_node **stack_a, t_node **stack_b, int print);
void	pb(t_node **stack_a, t_node **stack_b, int print);
void	ra(t_node **stack, int print);
void	rb(t_node **stack, int print);
void	rr(t_node **stack_a, t_node **stack_b, int print);
void	rra(t_node **stack, int print);
void	rrb(t_node **stack, int print);
void	rrr(t_node **stack_a, t_node **stack_b, int print);

void	test_functions(t_node **stack_a, t_node **stack_b);
void	sort3(t_node **stack);
void	sort5(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **stack_a, t_node **stack_b);
t_node	*median(t_node **stack, int len);
void	quicksort(t_node **stack_a, t_node **stack_b, int len);

void	k_sort(t_node **stack_a, t_node **stack_b);
void	sorted_index(t_node **stack_a);
void	which_rotation(t_node **stack_a, t_node *node_to_rotate, int i);
t_node	*find_element(t_node **stack, int index);
void	push_back(t_node **stack_a, t_node **stack_b, int len);

#endif