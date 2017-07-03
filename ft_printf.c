/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:03:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/05/08 22:03:45 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		skip(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		if (s[i] == '%')
			i++;
		i += isflag(&s[i]);
		i += iswidth(&s[i]);
		i += isprec(&s[i]);
		i += islen(&s[i]);
		i += isspec(&s[i]);
	}
	return (i);
}

static char		*get_format(t_format *fmt, char *s, va_list ap)
{
	checkfmt(fmt, s + 1, ap);
	getcontent(fmt, s, ap);
	return (fmt->ret);
}

static t_list	*get_vars(char *s, va_list ap)
{
	char		*t;
	t_list		*tmp;
	t_list		*vars;
	t_format	*fmt;

	vars = 0;
	fmt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			fmt = (t_format*)ft_memalloc(sizeof(t_format));
			t = get_format(fmt, s, ap);
			tmp = t ? ft_lstnew(t, fmt->ter + 1) : ft_lstnew(0, 0);
			ft_lstaddback(&vars, tmp);
			s += skip(s);
			if (fmt)
				delfmt(fmt);
		}
		else
			s++;
	}
	return (vars);
}

int				preprint(int fd, const char *format, t_list *vars)
{
	size_t	i;

	i = 0;
	while (*format)
	{
		if (*format == '%' && vars != NULL)
		{
			format += skip((char*)format);
			i += print_vars(fd, vars);
			vars = vars->next;
		}
		else
			i += ft_putchar(*format++);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*vars;
	t_list	*head;
	size_t	i;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	vars = get_vars((char*)format, ap);
	head = vars;
	i = preprint(1, format, vars);
	va_end(ap);
	ft_lstdel(&head, ft_bzero);
	return (i);
}
