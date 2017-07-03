/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 21:29:36 by coco              #+#    #+#             */
/*   Updated: 2017/05/20 21:29:37 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setflag(t_format *fmt, char *s)
{
	int		i;
	t_flags	*flags;

	i = 0;
	if (!isflag(&s[i]))
		return ;
	flags = (t_flags*)ft_memalloc(sizeof(t_flags));
	fmt->flags = *flags;
	while (isflag(&s[i]))
	{
		if (s[i] == '-')
			fmt->flags.dash = 1;
		else if (s[i] == '+')
			fmt->flags.plus = 1;
		else if (s[i] == ' ')
			fmt->flags.space = 1;
		else if (s[i] == '#')
			fmt->flags.hash = 1;
		else if (s[i] == '0' && s[i + 1] == '0')
			fmt->flags.doublezero = 1;
		else if (s[i] == '0')
			fmt->flags.zero = 1;
		i = fmt->flags.doublezero ? i + 2 : i + 1;
	}
}

void	setwidth(t_format *fmt, char *s, va_list ap)
{
	size_t	i;
	char	*t;

	s += skipto(s, 1);
	t = s;
	i = 0;
	while (*t >= '0' && *t <= '9')
	{
		t++;
		i++;
	}
	t = ft_strndup(s, i);
	if (*s == '*')
		fmt->width = va_arg(ap, int);
	else if (*s >= '0' && *s <= '9')
		fmt->width = ft_atoi(t);
	if (t)
		ft_memdel((void**)&t);
}

void	setprec(t_format *fmt, char *s, va_list ap)
{
	size_t	i;
	char	*t;

	s += skipto(s, 2);
	i = 0;
	if (s && *s++ == '.')
	{
		t = s;
		while (*t >= '0' && *t++ <= '9')
			i++;
		t = ft_strndup(s, i);
		if (!ft_strcmp(t, "0") || i == 0)
			fmt->flags.precded = 1;
		else if (*s == '*')
			fmt->prec = va_arg(ap, int);
		else if (*s >= '0' && *s <= '9')
			fmt->prec = ft_atoi(t);
		if (t)
			ft_memdel((void**)&t);
	}
}

void	setlen(t_format *fmt, char *s)
{
	int i;

	i = 0;
	s += skipto(s, 3);
	if (s[i] == 'h')
		fmt->len = s[i + 1] == 'h' ? "hh" : "h";
	else if (s[i] == 'l')
		fmt->len = s[i + 1] == 'l' ? "ll" : "l";
	else if (s[i] == 'j')
		fmt->len = "j";
	else if (s[i] == 'z')
		fmt->len = "z";
	else if (s[i] == 'L')
		fmt->len = "L";
}

void	setspec(t_format *fmt, char *s)
{
	s += skipto(s, 4);
	if (ft_isletter(*s, 'd') || *s == 'i')
		fmt->spec = ft_isletter(*s, 'd') ? *s : 'i';
	else if (ft_isletter(*s, 's') || ft_isletter(*s, 'c') ||
		ft_isletter(*s, 'u') || ft_isletter(*s, 'o') || ft_isletter(*s, 'x'))
		fmt->spec = *s;
	else if (*s == 'p' || *s == '%')
		fmt->spec = *s == 'p' ? 'p' : '%';
	else if (*s == 'b')
		fmt->spec = 'b';
	if (ft_isletter(fmt->spec, 'd') || fmt->spec == 'i' ||
		ft_isletter(fmt->spec, 'u'))
		fmt->base = 10;
	else if (ft_isletter(fmt->spec, 'x') || fmt->spec == 'p')
		fmt->base = 16;
	else if (ft_isletter(fmt->spec, 'o'))
		fmt->base = 8;
	else if (fmt->spec == 'b')
		fmt->base = 2;
}
