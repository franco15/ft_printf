/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 18:24:59 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/17 18:25:00 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	strflags(t_format *fmt)
{
	if (fmt->flags.dash)
		left_justify(fmt);
}

static void	strwidth(t_format *fmt)
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

static void	strprec(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (!l || fmt->prec >= l || (!fmt->prec && !fmt->flags.precded))
		return ;
	if (fmt->flags.precded)
	{
		ft_memdel((void**)&fmt->ret);
		return ;
	}
	tmp = ft_strnew(fmt->prec);
	ft_strncpy(tmp, fmt->ret, fmt->prec);
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void		convstr(t_format *fmt, va_list ap)
{
	char	*tmp;

	if (fmt->spec == 'S' || (fmt->len && !ft_strcmp(fmt->len, "l")))
		return (convwstr(fmt, ap));
	tmp = va_arg(ap, char*);
	if (tmp)
		fmt->ret = ft_strdup(tmp);
	else
		fmt->ret = ft_strdup("(null)");
	strprec(fmt);
	strwidth(fmt);
	strflags(fmt);
	fmt->ret ? fmt->ter = ft_strlen(fmt->ret) : 0;
}
