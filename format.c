/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 23:32:07 by lfranco-          #+#    #+#             */
/*   Updated: 2017/05/11 23:32:09 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		skipto(char *s, int a)
{
	int	i;

	i = 0;
	if (a >= 1)
		i += isflag(&s[i]);
	if (a >= 2)
		i += iswidth(&s[i]);
	if (a >= 3)
		i += isprec(&s[i]);
	if (a == 4)
		i += islen(&s[i]);
	return (i);
}

void	checkfmt(t_format *fmt, char *s, va_list ap)
{
	char *tmp;

	tmp = s;
	if (isflag(tmp) && (tmp += isflag(tmp)))
		setflag(fmt, s);
	if (iswidth(tmp) && (tmp += iswidth(tmp)))
		setwidth(fmt, s, ap);
	if (isprec(tmp) && (tmp += isprec(tmp)))
		setprec(fmt, s, ap);
	if (islen(tmp) && (tmp += islen(tmp)))
		setlen(fmt, s);
	if (isspec(tmp) && (tmp += isspec(tmp)))
		setspec(fmt, s);
}

void	getcontent(t_format *fmt, char *s, va_list ap)
{
	char	sp;

	sp = fmt->spec;
	s += skipto(s, 4);
	if (isspec(s))
	{
		if (ft_isletter(sp, 'd') || sp == 'i')
			convsint(fmt, ap);
		else if (sp == '%' || sp == 'b')
			(sp == '%') ? convperc(fmt) : convb(fmt, ap);
		else if (ft_isletter(sp, 'x') || ft_isletter(sp, 'o'))
			(ft_isletter(sp, 'x')) ? convhex(fmt, ap) : convoct(fmt, ap);
		else if (sp == 'p' || ft_isletter(sp, 'u'))
			(sp == 'p') ? convp(fmt, ap) : convuint(fmt, ap);
		else if (ft_isletter(sp, 's') || ft_isletter(sp, 'c'))
			(ft_isletter(sp, 's')) ? convstr(fmt, ap) : convchar(fmt, ap);
	}
}
