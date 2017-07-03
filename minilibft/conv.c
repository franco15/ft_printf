/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:52:46 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 01:52:49 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int			ft_atoi(char const *str)
{
	int	r;
	int	n;

	r = 0;
	n = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = (r * 10) + (*str - 48);
		str++;
	}
	return (r * n);
}

static int	ft_digitnum(long long int n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char		*ft_itoa_base(long long int n, int b)
{
	char			*num;
	size_t			size;
	int				neg;
	long long int	mod;

	neg = 0;
	size = ft_digitnum(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

static int	ft_digitnuml(unsigned long long int n, int base)
{
	int						i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char		*ft_itoa_basel(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789abcdef");
	if (value == 0 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_digitnuml(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}
