/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 21:05:11 by coco              #+#    #+#             */
/*   Updated: 2017/05/20 21:05:14 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./minilibft/minilibft.h"

typedef struct			s_flags
{
	int					dash;
	int					plus;
	int					space;
	int					hash;
	int					zero;
	int					doublezero;
	int					precded;
}						t_flags;

typedef struct			s_format
{
	t_flags				flags;
	int					width;
	int					prec;
	char				*len;
	char				spec;
	int					base;
	char				*ret;
	int					ter;
	int					ogretlen;
}						t_format;
/*
** ft_printf.c
*/
int						ft_printf(const char *format, ...);
int						preprint(int fd, const char *format, t_list *vars);

/*
** ft_printf_fd.c
*/
int						ft_printf_fd(int fd, const char *format, ...);

/*
** format.c
*/
int						skipto(char *s, int a);
void					checkfmt(t_format *fmt, char *s, va_list ap);
void					getcontent(t_format *fmt, char *s, va_list ap);

/*
** is.c
*/
int						isflag(char *s);
int						iswidth(char *s);
int						isprec(char *s);
int						islen(char *s);
int						isspec(char *s);

/*
** set.c
*/
void					setflag(t_format *fmt, char *s);
void					setwidth(t_format *fmt, char *s, va_list ap);
void					setprec(t_format *fmt, char *s, va_list ap);
void					setlen(t_format *fmt, char *s);
void					setspec(t_format *fmt, char *s);

/*
** sint.c
*/
void					convsint(t_format *fmt, va_list ap);

/*
** uint.c
*/
void					convuint(t_format *fmt, va_list ap);

/*
** oct.c
*/
void					convoct(t_format *fmt, va_list ap);

/*
** hex.c
*/
void					convhex(t_format *fmt, va_list ap);

/*
** str.c
*/
void					convstr(t_format *fmt, va_list ap);

/*
** char.c
*/
void					convchar(t_format *fmt, va_list ap);

/*
** p.c
*/
void					convp(t_format *fmt, va_list ap);

/*
** wstr.c
*/
void					convwchar(t_format *fmt, va_list ap);
void					convwstr(t_format *fmt, va_list ap);

/*
** extra.c
*/
void					left_justify(t_format *fmt);
void					addplus(t_format *fmt, int k);
void					addzero(t_format *fmt, int len);
void					addzerox(t_format *fmt, int len, char *tmp);
void					convperc(t_format *fmt);

/*
** utils.c
*/
size_t					print_vars(int fd, t_list *vars);
void					upperx(t_format *fmt);
void					delfmt(t_format *fmt);
void					convu(t_format *fmt, va_list ap);
void					convb(t_format *fmt, va_list ap);

#endif
