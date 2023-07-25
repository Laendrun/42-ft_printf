/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:56:14 by saeby             #+#    #+#             */
/*   Updated: 2023/03/12 20:58:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_num(t_flags *flags);

// cspdiuxX%

int	ft_printf(const char *fmt, ...)
{
	va_list			argp;
	t_flags			flags;
	int				i;

	va_start(argp, fmt);
	i = 0;
	flags.count = 0;
	while (*fmt != '\0')
	{
		flags.c = *fmt;
		if (flags.c != '%')
		{
			write(1, fmt, 1);
			fmt++;
			continue ;
		}
		fmt++;
		flags.length = 0;
		flags.prec = -1;
		flags.ladjust = 0;
		flags.padc = ' ';
		flags.plus_sign = 0;
		flags.sign_char = 0;
		flags.altfmt = 0;
		flags.prefix = 0;
		while (1)
		{
			flags.c = *fmt;
			if (flags.c == '#')
				flags.altfmt = 1;
			else if (flags.c == '-')
				flags.ladjust = 1;
			else if (flags.c == '+')
				flags.plus_sign = '+';
			else if (flags.c == ' ')
			{
				if (flags.plus_sign == 0)
					flags.plus_sign = ' ';
			}
			else
				break ;
			fmt++;
		}
		if (flags.c == '0')
		{
			flags.padc = '0';
			flags.c = *++fmt;
		}
		if (ft_isdigit(flags.c))
		{
			while (ft_isdigit(flags.c))
			{
				flags.length = 10 * flags.length + ctod(flags.c);
				flags.c = *++fmt;
			}
		}
		else if (flags.c == '*')
		{
			flags.length = va_arg(argp, int);
			flags.c = *++fmt;
			if (flags.length < 0)
			{
				flags.ladjust = !flags.ladjust;
				flags.length = -flags.length;
			}
		}
		if (flags.c == '.')
		{
			flags.c = *++fmt;
			if (ft_isdigit(flags.c))
			{
				flags.prec = 10 * flags.prec + ctod(flags.c);
				flags.c = *++fmt;
			}
			else if (flags.c == '*')
			{
				flags.prec = va_arg(argp, int);
				flags.c = *++fmt;
			}
		}
		if (flags.c == 'l')
			flags.c = *fmt;
		flags.capitals = 0;
		if (flags.c == 'c')
		{
			flags.c = va_arg(argp, int);
			write(1, &flags.c, 1);
		}
		else if (flags.c == 's')
		{
			char	*p;
			char	*p2;

			if (flags.prec == -1)
				flags.prec = 0x7fffffff;
			p = va_arg(argp, char *);
			if (p == (char *)0)
				p = "";
			if (flags.length > 0 && !flags.ladjust)
			{
				flags.n = 0;
				p2 = p;
				while (*p != '\0' && flags.n < flags.prec)
				{
					flags.n++;
					p++;
				}
				p = p2;
				while (flags.n < flags.length)
				{
					write(1, " ", 1);
					flags.n++;
				}
			}
			flags.n = 0;
			while (*p != '\0')
			{
				if (++flags.n > flags.prec || (flags.length > 0 && flags.n > flags.length))
					break ;
				write(1, p++, 1);
			}
			if (flags.n < flags.length && flags.ladjust)
			{
				while (flags.n < flags.length)
				{
					write(1, " ", 1);
					flags.n++;
				}
			}
		}
		else if (flags.c == 'd' || flags.c == 'i')
		{
			flags.base = 10;
			flags.n = va_arg(argp, long);
			if (flags.n >= 0)
			{
				flags.u = flags.n;
				flags.sign_char = flags.plus_sign;
			}
			else
			{
				flags.u = -flags.n;
				flags.sign_char = '-';
			}
			print_num(&flags);
		}
		else if (flags.c == 'p' || flags.c == 'x' || flags.c == 'X')
		{
			if (flags.c == 'p')
			{
				flags.altfmt = 1;
				flags.base = 16;
				flags.u = va_arg(argp, unsigned long);
				print_num(&flags);
			}
			else if (flags.c == 'x')
			{
				flags.base = 16;
				flags.u = va_arg(argp, unsigned long);
				print_num(&flags);
			}
			else if (flags.c == 'X')
			{
				flags.base = 16;
				flags.capitals = 16;
				flags.u = va_arg(argp, unsigned long);
				print_num(&flags);
			}
		}
		else if (flags.c == 'u')
		{
			flags.base = 10;
			flags.u = va_arg(argp, unsigned long);
			print_num(&flags);
		}
		else
			ft_putchar('%');
		fmt++;
	}
	va_end(argp);
	return (0);
}

void	choose_prefix(t_flags *flags)
{
	if (flags->u != 0 && flags->altfmt)
	{
		if (flags->base == 8)
			flags->prefix = "0";
		else if (flags->base == 16)
			flags->prefix = "0x";
	}
}

int		print_num(t_flags *flags)
{
	char	buf[MAXBUF];
	char	*p;

	p = &buf[MAXBUF - 1];
	choose_prefix(flags);
	while (flags->u != 0)
	{
		*p-- = "0123456789abcdef0123456789ABCDEF"[(flags->u % flags->base) + flags->capitals];
		flags->u /= flags->base;
	}
	flags->length -= (&buf[MAXBUF - 1] - p);
	if (flags->sign_char)
		flags->length--;
	if (flags->prefix)
		flags->length -= ft_strlen((const char *) flags->prefix);
	if (flags->padc == ' ' && !flags->ladjust)
		padd(flags);
	if (flags->sign_char)
		ft_putchar(flags->sign_char);
	if (flags->prefix)
		ft_putstr((const char *) flags->prefix);
	if (flags->padc == '0')
		padd(flags);
	while (++p != &buf[MAXBUF])
		ft_putchar(*p);
	if (flags->ladjust)
		adjust_left(flags);
	return (0);
}
