/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:23:12 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 19:23:13 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	intlen(t_format *fmt, va_list ap)
{
	if (fmt->spec == 'O')
		fmt->ret = ft_itoa_base(va_arg(ap, long), fmt->base);
	else if (!fmt->len)
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
	fmt->ogretlen = fmt->ret ? ft_strlen(fmt->ret) : 0;
}

static void	intflags(t_format *fmt, char *tmp)
{
	int	len;

	len = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (fmt->flags.plus)
	{
		if (len && (fmt->width > len && fmt->flags.zero))
			fmt->ret[0] = '+';
		else
			addplus(fmt, 0);
	}
	if (fmt->flags.dash)
		left_justify(fmt);
	if (fmt->flags.hash)
	{
		if (!fmt->ret)
			fmt->ret = ft_strdup("0");
		else
			addzero(fmt, len);
	}
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

void		convoct(t_format *fmt, va_list ap)
{
	char	*tmp;

	tmp = 0;
	intlen(fmt, ap);
	intprec(fmt);
	intwidth(fmt);
	intflags(fmt, tmp);
	fmt->ret ? fmt->ter = ft_strlen(fmt->ret) : 0;
}
