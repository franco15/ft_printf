/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:44:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 01:44:05 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if ((dup = ft_strnew(ft_strlen(s1))))
		return (ft_strcpy(dup, s1));
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char	*ft_strncatalrevez(char *s, char c, size_t n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	if (!s)
		ret = ft_strnew(n);
	else
		ret = ft_strnew(ft_strlen(s) + n);
	while (n-- > 0)
		ret[i++] = c;
	ret[i] = '\0';
	if (!s)
		return (ret);
	return (ft_strcat(ret, s));
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p;
	size_t	l;

	l = ft_strlen(src);
	p = dst;
	if (len > l)
	{
		while (*src)
		{
			*p++ = *src++;
			len--;
		}
		while (len-- > 0)
			*p++ = '\0';
	}
	else
		while (len-- > 0)
			*p++ = *src++;
	return (dst);
}

char	*ft_strndup(const char *s1, size_t l)
{
	char	*dup;

	if ((dup = ft_strnew(l)))
		return (ft_strncpy(dup, s1, l));
	return (0);
}
