/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:32:39 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/19 12:52:03 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief writes int nbr to stdout with base 16
/// @return cha
int	rec_puthex(unsigned long nbr, char *base)
{
	int	written_chars;

	written_chars = 0;
	if (nbr >= 16)
	{
		written_chars = rec_puthex(nbr / 16, base);
		if (written_chars == -1)
			return (-1);
	}
	if (ft_putchar(base[nbr % 16]) == -1)
		return (-1);
	return (++written_chars);
}

/// @brief writes int to stdout with base 16, lowercase hex
/// @return how many chars are written to stdout, < 0 if write fails
int	ft_puthex_lowercase(unsigned long nbr)
{
	return (rec_puthex(nbr, "0123456789abcdef"));
}

/// @brief writes int to stdout with base 16,  uppercase hex
/// @return how many chars are written to stdout, return < 0 if write fails
int	ft_puthex_uppercase(unsigned long nbr)
{
	return (rec_puthex(nbr, "0123456789ABCDEF"));
}
