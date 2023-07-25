/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:57:32 by saeby             #+#    #+#             */
/*   Updated: 2023/03/12 20:53:02 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# define MAXBUF 64

typedef struct s_flags
{
	int				length;
	int				prec;
	int				ladjust;
	char			padc;
	long			n;
	unsigned long	u;
	int				plus_sign;
	int				sign_char;
	int				altfmt;
	int				trunc;
	int				base;
	char			c;
	int				capitals;
	int				count;
	char			*prefix;
}	t_flags;

int		ft_printf(const char *fmt, ...);

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
char	ctod(int c);
int		adjust_left(t_flags *flags);
int		padd(t_flags *flags);

#endif