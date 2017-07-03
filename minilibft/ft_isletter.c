/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isletter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 05:35:44 by coco              #+#    #+#             */
/*   Updated: 2017/06/09 05:35:46 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	ft_isletter(char uk, char k)
{
	if (uk == k || uk == (k - 32) || uk == (k + 32))
		return (1);
	return (0);
}

int	ft_onlyspaces(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i++] != ' ')
			j++;
	return (j);
}

int	ft_onlyzeros(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i++] != '0')
			j++;
	return (j);
}
