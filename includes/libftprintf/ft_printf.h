/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:37:15 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 12:31:43 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_printf(const	char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex_lowercase(unsigned long nbr);
int		ft_puthex_uppercase(unsigned long nbr);
int		ft_put_ptr(void *p);
char	*get_next_line(int fd);
int		ft_strchr2(const char *s, int c);
char	*ft_strjoin_free_s1(char *s1, char *s2);
char	*ft_substr2(char *s, size_t len);
int		ft_strlen2(char *str);
void	*ft_calloc2(size_t count, size_t size);

#endif