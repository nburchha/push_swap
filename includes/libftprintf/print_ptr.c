/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:56:41 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/19 11:45:30 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(void *p)
{
	int	written_chars;

	written_chars = 0;
	written_chars = ft_putstr("0x");
	if (written_chars == -1)
		return (-1);
	written_chars += ft_puthex_lowercase((unsigned long)p);
	if (written_chars == 2 - 1)
		return (-1);
	return (written_chars);
}
