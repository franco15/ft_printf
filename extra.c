/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 12:27:18 by coco              #+#    #+#             */
/*   Updated: 2017/05/21 12:27:21 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	left_justify(t_format *fmt)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = fmt->ret ? ft_strnew(ft_strlen(fmt->ret)) : 0;
	tmp[ft_strlen(fmt->ret)] = '\0';
	while (fmt->ret[i] == ' ' || (fmt->flags.zero && fmt->ret[i] == '0') ||
		fmt->ret[i] == '+' || fmt->ret[i] == '-')
		++i;
	if (ft_strchr(fmt->ret, '-') || ft_strchr(fmt->ret, '+'))
		tmp[j++] = ft_strchr(fmt->ret, '-') ? '-' : '+';
	while (fmt->ret[i] != '\0')
		tmp[j++] = fmt->ret[i++];
	i = fmt->flags.zero ? 1 : 0;
	i = !ft_strchr(fmt->ret, '-') && !ft_strchr(fmt->ret, '-') ? 0 : i;
	while (fmt->ret[i] == ' ' || (fmt->flags.zero && fmt->ret[i] == '0'))
	{
		tmp[j++] = fmt->flags.doublezero ? '0' : ' ';
		i++;
	}
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void	addplus(t_format *fmt, int k)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (fmt->ret[k] < '0' || fmt->ret[k] > '9')
		k++;
	tmp = k == 0 ? ft_strnew(ft_strlen(fmt->ret) + 1) :
		ft_strnew(ft_strlen(fmt->ret));
	k = k > 0 ? k - 1 : k;
	while (fmt->ret[i])
	{
		if (j == k)
		{
			tmp[j++] = '+';
			i = k == 0 ? i : i + 1;
			i = fmt->flags.zero ? i + 1 : i;
		}
		tmp[j++] = fmt->ret[i++];
	}
	tmp[j] = '\0';
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void	addzero(t_format *fmt, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!ft_strcmp(fmt->ret, "0") || (fmt->flags.zero && ((*fmt->ret == '0' &&
		*fmt->ret + 1 == '0') || *fmt->ret == '0')))
		return ;
	tmp = fmt->width > fmt->ogretlen ? ft_strnew(len) : ft_strnew(len + 1);
	while (fmt->ret[j] == ' ')
		tmp[i++] = fmt->ret[j++];
	i = i > 0 ? i - 1 : i;
	tmp[i++] = '0';
	while (i < len || (!fmt->width && i <= len))
		tmp[i++] = fmt->ret[j++];
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void	addzerox(t_format *fmt, int len, char *tmp)
{
	if (!fmt->ret || !ft_strcmp(fmt->ret, "0"))
		return ;
	if (fmt->ogretlen == len)
		tmp = (fmt->spec == 'x') ? ft_strjoin("0x", fmt->ret)
		: ft_strjoin("0X", fmt->ret);
	else if (fmt->flags.zero && (fmt->ret[0] == '0' && fmt->ret[1] == '0'))
	{
		tmp = ft_strdup(fmt->ret);
		tmp[1] = fmt->spec == 'x' ? 'x' : 'X';
	}
	else if (fmt->flags.dash)
	{
		tmp = ft_strnew(len);
		(fmt->spec == 'x') ? ft_strcat(tmp, "0x") : ft_strcat(tmp, "0X");
		ft_strncat(tmp, fmt->ret, len - 2);
	}
	else
	{
		tmp = ft_strnew(len);
		ft_strncat(tmp, fmt->ret, len - fmt->ogretlen - 2);
		(fmt->spec == 'x') ? ft_strcat(tmp, "0x") : ft_strcat(tmp, "0X");
		ft_strcat(tmp, fmt->ret + (len - fmt->ogretlen));
	}
	fmt->ret ? ft_memdel((void**)&fmt->ret) : 0;
	fmt->ret = tmp;
}

void	convperc(t_format *fmt)
{
	int	i;

	i = 0;
	if (fmt->width)
	{
		fmt->ret = ft_strnew(fmt->width);
		while (i < fmt->width)
			fmt->ret[i++] = fmt->flags.zero && !fmt->flags.dash ? '0' : ' ';
		fmt->ret[i] = '\0';
		if (fmt->flags.dash)
			fmt->ret[0] = '%';
		else
			fmt->ret[--i] = '%';
	}
	else
		fmt->ret = ft_strdup("%");
	fmt->ter = ft_strlen(fmt->ret);
}
