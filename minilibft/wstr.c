/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 03:11:33 by coco              #+#    #+#             */
/*   Updated: 2017/06/23 03:11:35 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

wchar_t	*ft_wstrnew(size_t len)
{
	wchar_t	*s;

	if (!(s = ft_memalloc((sizeof(wchar_t) * len))))
		return (0);
	return (s);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
		j += ft_uclen(s[i++]);
	return (j);
}

wchar_t	*ft_wstrdup(const wchar_t *src)
{
	wchar_t	*new;
	size_t	len;

	if (!src)
		return (0);
	len = ft_wstrlen(src);
	if (!len)
		return (0);
	new = ft_wstrnew(len * sizeof(wchar_t));
	if (!new)
		return (0);
	new = ft_memcpy(new, src, sizeof(wchar_t) * len);
	return (new);
}

char	*ft_wstr2str(wchar_t *ws)
{
	size_t	i;
	size_t	pos;
	char	*ret;

	i = 0;
	pos = 0;
	ret = ft_strnew(ft_wstrlen(ws));
	while (ws[i])
	{
		ft_uctoa(ws[i], ret + pos);
		pos += ft_uclen(ws[i++]);
	}
	return (ret);
}
