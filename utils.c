/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:46:26 by coco              #+#    #+#             */
/*   Updated: 2017/05/17 21:46:28 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_vars(int fd, t_list *vars)
{
	char	*tmp;

	tmp = 0;
	vars->content ? tmp = ft_strdup((char*)vars->content) : 0;
	if (!tmp)
		return (0);
	if ((vars->size - 1) == 1 && *tmp == '\0')
		write(fd, &(*tmp), 1);
	else
		ft_putstr(tmp);
	ft_memdel((void**)&tmp);
	return (vars->size - 1);
}

void		upperx(t_format *fmt)
{
	int	i;

	i = 0;
	while (fmt->ret[i])
	{
		if (fmt->ret[i] >= 97 && fmt->ret[i] <= 122)
			fmt->ret[i] = fmt->ret[i] - 32;
		i++;
	}
}

static void	delflags(t_format *fmt)
{
	t_flags	*tmp;

	tmp = &fmt->flags;
	if (tmp)
	{
		tmp->dash = 0;
		tmp->plus = 0;
		tmp->space = 0;
		tmp->hash = 0;
		tmp->zero = 0;
		tmp->doublezero = 0;
		tmp->precded = 0;
		ft_memdel((void**)&tmp);
	}
}

void		delfmt(t_format *fmt)
{
	delflags(fmt);
	fmt->len = 0;
	free(fmt->ret);
	fmt->width = 0;
	fmt->prec = 0;
	fmt->spec = 0;
	fmt->base = 0;
	fmt->ter = 0;
	fmt->ogretlen = 0;
	fmt = NULL;
}

void		convb(t_format *fmt, va_list ap)
{
	fmt->ret = ft_itoa_basel(va_arg(ap, unsigned long long), fmt->base);
	fmt->ter = ft_strlen(fmt->ret);
}
