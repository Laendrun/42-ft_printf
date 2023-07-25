/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:14:56 by saeby             #+#    #+#             */
/*   Updated: 2023/03/12 20:46:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	ctod(int c)
{
	return (c - '0');
}

int	ft_putstr(const char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	adjust_left(t_flags *flags)
{
	int	count;

	count = 0;
	while (--flags->length >= 0)
		count += ft_putchar(' ');
	return (count);
}

int	padd(t_flags *flags)
{
	int	count;

	count = 0;
	while (--flags->length >= 0)
		count += ft_putchar(flags->padc);
	return (count);
}
