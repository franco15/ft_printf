/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:40:04 by lfranco-          #+#    #+#             */
/*   Updated: 2017/05/15 23:40:06 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isflag(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '-' || s[i] == '+' || s[i] == ' ' ||
			s[i] == '#' || (s[i] == '0' && s[i + 1] == '0') || s[i] == '0'))
		i = s[i] == '0' && s[i + 1] == '0' ? i + 2 : i + 1;
	return (i);
}

int	iswidth(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9') || s[i] == '*'))
		++i;
	return (i);
}

int	isprec(char *s)
{
	int	i;

	i = 0;
	if (*s && s[i] != '.')
		return (0);
	while (s[i] != '\0' && (s[++i] >= '0' && s[i] <= '9'))
		;
	return (i);
}

int	islen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' ||
		s[i] == 'z' || s[i] == 'L'))
		++i;
	return (i);
}

int	isspec(char *s)
{
	int		i;
	char	*spec;

	spec = "sSpdDioOuUxXcCb";
	i = 0;
	if (*s)
	{
		if (s[0] == '%')
			return (1);
		while (spec[i])
			if (*s == spec[i++])
				return (1);
	}
	return (0);
}
