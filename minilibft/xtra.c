/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:55:10 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 01:55:11 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int		ft_baselen(long long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 11 || c == 13 || c == 10 || c == '\f');
}

void	*ft_realloc(void *ptr, size_t size, size_t newsize)
{
	void	*new;

	if (ptr && newsize && size)
	{
		new = ft_memalloc(newsize);
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	else
		new = ft_memalloc(newsize);
	return (new);
}
