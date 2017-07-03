/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:02:12 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/15 11:02:13 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	intlen(t_format *fmt, va_list ap)
{
	char	hh;
	short	h;

	if (fmt->spec == 'D')
		fmt->ret = ft_itoa_base(va_arg(ap, long), fmt->base);
	else if (!fmt->len)
		fmt->ret = ft_itoa_base(va_arg(ap, int), fmt->base);
	else if (!ft_strcmp(fmt->len, "h") && (h = (short)va_arg(ap, int)))
		fmt->ret = ft_itoa_base(h, fmt->base);
	else if (!ft_strcmp(fmt->len, "hh") && (hh = (char)va_arg(ap, int)))
		fmt->ret = ft_itoa_base(hh, fmt->base);
	else if (!ft_strcmp(fmt->len, "l"))
		fmt->ret = ft_itoa_base(va_arg(ap, long), fmt->base);
	else if (!ft_strcmp(fmt->len, "ll"))
		fmt->ret = ft_itoa_base(va_arg(ap, long long), fmt->base);
	else if (!ft_strcmp(fmt->len, "j"))
		fmt->ret = ft_itoa_base(va_arg(ap, intmax_t), fmt->base);
	else if (!ft_strcmp(fmt->len, "z"))
		fmt->ret = ft_itoa_base(va_arg(ap, ssize_t), fmt->base);
	else if (!ft_strcmp(fmt->len, "t"))
		fmt->ret = ft_itoa_base(va_arg(ap, ptrdiff_t), fmt->base);
	fmt->ret && !fmt->width && !ft_strcmp(fmt->ret, "0") && fmt->flags.precded
	? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret && fmt->width && !ft_strcmp(fmt->ret, "0") ? (fmt->ret[0] = ' ')
	: 0;
}

static void	intflags(t_format *fmt)
{
	int		len;
	char	*tmp;

	tmp = 0;
	len = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (fmt->flags.plus && !ft_strchr(fmt->ret, '-'))
	{
		if (len && (fmt->width > len && fmt->flags.zero))
			fmt->ret[0] = '+';
		else
			addplus(fmt, 0);
	}
	if (fmt->flags.dash)
		left_justify(fmt);
	if ((fmt->flags.space && !fmt->flags.plus) && fmt->width < len &&
		!ft_strchr(fmt->ret, '-'))
	{
		tmp = ft_strjoin(" ", fmt->ret);
		fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
		fmt->ret = tmp;
	}
}

static void	intwidth(t_format *fmt)
{
	int		l;
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if ((!l && !fmt->width) || fmt->width < l || (fmt->width == l &&
		!ft_strchr(fmt->ret, '-')))
		return ;
	if (fmt->flags.zero && !fmt->flags.space && (fmt->spec != 'i' ||
		!fmt->prec))
		tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->width - l));
	else
		tmp = ft_strncatalrevez(fmt->ret, ' ', (fmt->width - l));
	if (fmt->ret && ft_strchr(fmt->ret, '-'))
	{
		while (tmp[i] != '-')
			++i;
		tmp[i] = (fmt->flags.zero && !fmt->flags.space) ? '0' : '-';
		tmp[0] = (fmt->flags.zero && !fmt->flags.space) ? '-' : ' ';
	}
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

static void	intprec(t_format *fmt)
{
	int		l;
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (!l || fmt->prec < l || fmt->flags.precded)
		return ;
	if (fmt->prec == l && !ft_strchr(fmt->ret, '-'))
		return ;
	if (!(ft_strchr(fmt->ret, '-')))
		tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->prec - l));
	else
	{
		tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->prec - l + 1));
		while (tmp[i] != '-')
			++i;
		while (i > 0)
			tmp[i--] = '0';
		tmp[i] = '-';
	}
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void		convsint(t_format *fmt, va_list ap)
{
	intlen(fmt, ap);
	intprec(fmt);
	intwidth(fmt);
	intflags(fmt);
	fmt->ret ? fmt->ter = ft_strlen(fmt->ret) : 0;
	if (fmt->ret && !fmt->width && !ft_strcmp(fmt->ret, "0") &&
		fmt->flags.precded)
		fmt->ter = 0;
}
