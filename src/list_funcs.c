/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niklasburchhardt <niklasburchhardt@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:57:26 by niklasburch       #+#    #+#             */
/*   Updated: 2024/01/04 01:24:11 by niklasburch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew_mod(void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_node	*ft_lstlast_mod(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_lstadd_front_mod(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_mod(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		ft_lstadd_front_mod(lst, new);
	else
		ft_lstlast_mod(*lst)->next = new;
}

void	ft_lstclear_mod(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

int	ft_lstsize_mod(t_node *lst)
{
	int		i;
	t_node	*tmp;

	if (lst == NULL)
		return (0);
	tmp = lst;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

