/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:55:23 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/13 17:43:15 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief calls functions depending on input to write args to stdout
/// @return amount characters written
int	print_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_puthex_lowercase(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_uppercase(va_arg(args, unsigned int)));
	return (-1);
}

int	process_string(const char *str, va_list args)
{
	int	i;
	int	j;
	int	char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			j = print_arg(str[i], args);
		}
		else
			j = ft_putchar(str[i]);
		if (j < 0)
			return (-1);
		char_count += j;
		i++;
	}
	return (char_count);
}

int	ft_printf(const	char *str, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	char_count = process_string(str, args);
	if (char_count == -1)
		return (va_end(args), -1);
	va_end(args);
	return (char_count);
}
