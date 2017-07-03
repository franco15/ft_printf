/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:47:13 by lfranco-          #+#    #+#             */
/*   Updated: 2017/06/07 01:47:14 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *elem;

	if (!(elem = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->size = 0;
	}
	else
	{
		elem->content = (void*)ft_memalloc(size);
		elem->content = ft_memcpy(elem->content, content, size);
		elem->size = size;
	}
	elem->next = NULL;
	return (elem);
}

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!*alst && !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstdel(t_list **alst, void (*bzero)(void *, size_t))
{
	t_list	*t;
	t_list	*tt;

	t = *alst;
	while (t)
	{
		tt = t;
		bzero(t->content, t->size);
		t = tt->next;
	}
	free(*alst);
	*alst = NULL;
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	p = *alst;
	del(p->content, p->size);
	free(*alst);
	*alst = NULL;
}
