/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:14:30 by lfranco-          #+#    #+#             */
/*   Updated: 2017/02/28 18:14:31 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <inttypes.h>

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char const *str);
char				*ft_itoa_base(long long n, int b);
char				*ft_itoa_basel(unsigned long long int value, int base);
char				*ft_strnew(size_t size);
char				*ft_strndup(const char *s1, size_t l);
char				*ft_strchr(const char *s, int c);
void				*ft_memalloc(size_t size);
size_t				ft_putchar(char c);
void				ft_strdel(char **as);
size_t				ft_putstr(char const *s);
void				*ft_realloc(void *ptr, size_t size, size_t newsize);
size_t				ft_strlen(const char *s);
char				*ft_strncatalrevez(char *s, char c, size_t n);
int					ft_isspace(int c);
int					ft_isdigit(int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_lstdel(t_list **alst, void (*bzero)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
int					ft_baselen(long long value, int base);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const	char *src);
void				ft_lstaddback(t_list **alst, t_list *ne);
t_list				*ft_lstnew(void const *content, size_t size);
int					ft_isletter(char uk, char k);
int					ft_onlyspaces(char *s);
int					ft_onlyzeros(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
wchar_t				*ft_wstrnew(size_t len);
wchar_t				*ft_wstrdup(const wchar_t *src);
char				*ft_wstr2str(wchar_t *ws);
size_t				ft_wstrlen(const wchar_t *s);
void				ft_uctoa(wchar_t c, char *str);
int					ft_uclen(wchar_t c);

#endif
