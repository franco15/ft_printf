/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:51:23 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 01:51:24 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((p = malloc(size)))
	{
		while (i < size)
			p[i++] = '\0';
		return (p);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p;
	const char	*s;

	s = src;
	p = dst;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*p++ = *s++;
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len-- > 0)
		*s++ = c;
	return (b);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}
