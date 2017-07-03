/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:54:19 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/19 15:54:20 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	charflags(t_format *fmt)
{
	if (fmt->flags.dash)
		left_justify(fmt);
}

static void	charwidth(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	!l && fmt->width ? l = 1 : 0;
	if ((!l && !fmt->width) || fmt->width <= l)
		return ;
	if (fmt->flags.zero && !fmt->flags.space)
		tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->width - l));
	else
		tmp = ft_strncatalrevez(fmt->ret, ' ', (fmt->width - l));
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
	(int)ft_strlen(fmt->ret) >= fmt->ter && (!ft_onlyspaces(fmt->ret) ||
	!ft_onlyzeros(fmt->ret)) ? fmt->ter += ft_strlen(fmt->ret) :
	(fmt->ter = ft_strlen(fmt->ret));
}

void		convchar(t_format *fmt, va_list ap)
{
	char	tmp;

	if (fmt->spec == 'C' || (fmt->len && !ft_strcmp(fmt->len, "l")))
		return (convwchar(fmt, ap));
	tmp = va_arg(ap, int);
	fmt->ret = ft_strnew(1);
	fmt->ret[0] = tmp;
	fmt->ter = 1;
	charwidth(fmt);
	charflags(fmt);
}
