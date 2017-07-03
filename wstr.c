/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:43:56 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/21 22:43:58 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convwstr(t_format *fmt, va_list ap)
{
	wchar_t	*tmp;

	tmp = va_arg(ap, wchar_t*);
	if (!tmp)
		fmt->ret = ft_strdup("(null)");
	else
	{
		tmp = ft_wstrdup(tmp);
		fmt->ret = ft_wstr2str(tmp);
		ft_memdel((void**)&tmp);
	}
	fmt->ter = ft_strlen(fmt->ret);
}

void	convwchar(t_format *fmt, va_list ap)
{
	int		len;
	wchar_t	tmp;

	tmp = va_arg(ap, wchar_t);
	len = ft_uclen(tmp);
	fmt->ret = ft_strnew(len);
	ft_uctoa(tmp, fmt->ret);
	fmt->ter = ft_strlen(fmt->ret);
}
