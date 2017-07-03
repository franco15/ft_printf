/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 04:53:36 by coco              #+#    #+#             */
/*   Updated: 2017/06/09 04:53:37 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	intlen(t_format *fmt, va_list ap)
{
	if (!fmt->len)
		fmt->ret = (fmt->flags.precded && !fmt->prec) ? 0 :
		ft_itoa_basel(va_arg(ap, unsigned int), fmt->base);
	else if (!ft_strcmp(fmt->len, "h"))
		fmt->ret = ft_itoa_basel(va_arg(ap, unsigned int), fmt->base);
	else if (!ft_strcmp(fmt->len, "hh"))
		fmt->ret = ft_itoa_basel(va_arg(ap, unsigned int), fmt->base);
	else if (!ft_strcmp(fmt->len, "l"))
		fmt->ret = ft_itoa_basel(va_arg(ap, unsigned long long), fmt->base);
	else if (!ft_strcmp(fmt->len, "ll"))
		fmt->ret = ft_itoa_basel(va_arg(ap, unsigned long long), fmt->base);
	else if (!ft_strcmp(fmt->len, "j"))
		fmt->ret = ft_itoa_basel(va_arg(ap, uintmax_t), fmt->base);
	else if (!ft_strcmp(fmt->len, "z"))
		fmt->ret = ft_itoa_basel(va_arg(ap, size_t), fmt->base);
	else if (!ft_strcmp(fmt->len, "t"))
		fmt->ret = ft_itoa_basel(va_arg(ap, unsigned long long), fmt->base);
	fmt->ret ? fmt->ogretlen = ft_strlen(fmt->ret) : 0;
	fmt->ret && fmt->spec == 'X' ? upperx(fmt) : 0;
}

static void	intflags(t_format *fmt)
{
	int		len;
	char	*tmp;

	tmp = 0;
	len = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (fmt->flags.plus)
		len && (fmt->width > len && fmt->flags.zero) ? fmt->ret[0] = '+'
		: addplus(fmt, 0);
	if (fmt->flags.dash)
		left_justify(fmt);
	if (fmt->flags.hash)
		addzerox(fmt, len, tmp);
	if ((fmt->flags.space && !fmt->flags.plus) && fmt->width < len)
	{
		tmp = ft_strjoin(" ", fmt->ret);
		fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
		fmt->ret = tmp;
	}
}

static void	intwidth(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if ((!l && !fmt->width) || fmt->width <= l)
		return ;
	if (fmt->flags.zero && !fmt->flags.space)
		tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->width - l));
	else
		tmp = ft_strncatalrevez(fmt->ret, ' ', (fmt->width - l));
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

static void	intprec(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (!l || fmt->prec < l || fmt->flags.precded)
		return ;
	if (fmt->prec == l)
		return ;
	tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->prec - l));
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void		convhex(t_format *fmt, va_list ap)
{
	intlen(fmt, ap);
	intprec(fmt);
	intwidth(fmt);
	intflags(fmt);
	fmt->ret ? fmt->ter = ft_strlen(fmt->ret) : 0;
}
