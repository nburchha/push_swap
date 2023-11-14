/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_idu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:34:24 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/19 10:53:16 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Outputs the unsigned integer ’n’ to the given file descriptor.
/// @param n The integer to output
int	ft_putunbr(unsigned int n)
{
	if (n >= 10)
	{
		if (ft_putunbr(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (ft_count_digits(n));
}

/// @brief Outputs the integer ’n’ to the given file descriptor.
/// @param n The integer to output
/// @param fd  The file descriptor on which to write.
/// @return count of chars being written
int	ft_putnbr(int n)
{
	unsigned int	u_n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		u_n = (unsigned int)(n * -1);
		i = 1;
	}
	else
		u_n = (unsigned int) n;
	j = ft_putunbr(u_n);
	if (j == -1)
		return (-1);
	return (i + j);
}
