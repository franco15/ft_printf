/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:15:25 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/21 20:15:26 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	p0x(t_format *fmt)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while (fmt->ret && fmt->ret[i] == ' ')
		i++;
	if (i == 0)
		tmp = fmt->ret ? ft_strjoin("0x", fmt->ret) : ft_strdup("0x");
	else if (i == 1)
	{
		tmp = ft_strnew(ft_strlen(fmt->ret));
		tmp = ft_strcat(tmp, "0x");
		tmp = ft_strcat(tmp, fmt->ret + 1);
	}
	else
	{
		fmt->ret[i - 1] = 'x';
		fmt->ret[i - 2] = '0';
	}
	fmt->ret && tmp ? ft_memdel((void**)&fmt->ret) : 0;
	tmp ? fmt->ret = tmp : 0;
}

static void	pwidth(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if ((!l && !fmt->width) || fmt->width <= l)
		return ;
	tmp = ft_strncatalrevez(fmt->ret, ' ', (fmt->width - l));
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

static void	pprec(t_format *fmt)
{
	int		l;
	char	*tmp;

	tmp = 0;
	l = fmt->ret ? ft_strlen(fmt->ret) : 0;
	if (!l || fmt->prec < l || fmt->flags.precded)
		return ;
	if (fmt->prec == l && !ft_strchr(fmt->ret, '-'))
		return ;
	tmp = ft_strncatalrevez(fmt->ret, '0', (fmt->prec - l));
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void		convp(t_format *fmt, va_list ap)
{
	uintmax_t	i;

	i = va_arg(ap, uintmax_t);
	fmt->ret = ft_itoa_basel(i, fmt->base);
	if (!fmt->width && !fmt->prec && fmt->flags.precded &&
		!ft_strcmp(fmt->ret, "0"))
		ft_memdel((void**)&fmt->ret);
	pprec(fmt);
	pwidth(fmt);
	p0x(fmt);
	fmt->ret ? fmt->ter = ft_strlen(fmt->ret) : 0;
}
