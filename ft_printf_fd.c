/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:03:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/05/08 22:03:45 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...)
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
	i = preprint(fd, format, vars);
	va_end(ap);
	ft_lstdel(&head, ft_bzero);
	return (i);
}
