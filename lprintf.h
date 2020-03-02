/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:58 by motoure           #+#    #+#             */
/*   Updated: 2020/02/24 10:25:03 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LPRINTF_H
# define LPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define DEC "0123456789"
# define HEXD "0123456789abcdef"
# define MAJHEXD "0123456789ABCDEF"
# define STAR '*'
# define DASH '-'
# define ZERO '0'
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_t_curr
{
	char		*arg;
	char		*raw_arg;
	char		type;
	int			precision;
	int			width;
	int			width_type;

}				t_curr;

int				ft_atoi(char *str);
int				ft_nbrlen(int n);
int				ft_nbrlen_u(unsigned int n);
int				ft_strlen(char *str);
int				ft_printf(const char *str, ...);
int				is_hidden(char *str);
int				ft_isprint(int c);
int				fill_struct(t_curr *flag);
int				ft_ptrlen(unsigned long int ptr);
int				hidden_strlen(char *str, char *tmp);
int				contain_num(char *str);
int				print_struct(t_curr *flag, va_list args);
int				c_str(char *str, char c);
int				is_num(char c);
int				is_arg(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
void			ft_putptr(unsigned long int ptr, t_curr *flag);
void			ft_putchar_str(char **str, char c);
char			*ft_putnbr_base_u(unsigned int n, char *base);
char			*ft_putnbr_base(int n, char *base);
char			*ft_strrev(char *str);
char			*ft_strdup(const char *s1);
char			*get_next_arg(const char *str, int i, va_list args);
char			*hidden_of(char *str);
char			*get_width(t_curr *flag);
void			*ft_realloc(void *ptr, size_t size);
void			ft_memsub(void **dst, void *src, size_t index, int max);
void			write_const(const char *str, int *i);
void			arg_putptr(t_curr *flag, va_list args, int *ret);
void			arg_putchar(t_curr *flag, va_list args, int *ret);
void			arg_putstr(t_curr *flag, va_list args, int *ret);
void			print_value_u(t_curr *flag, int n, int *to_ret);
void			write_width(t_curr *flag, int len, int exception);
void			write_precision(int precision, int len);
void			ft_str(char *str);
void			fill_width_type(t_curr *flag);
void			fill_precision(t_curr *flag);
void			fill_width(t_curr *flag);
void			arg_puthexa(t_curr *flag, va_list args, int *ret);
void			arg_putunsigned(t_curr *flag, va_list args, int *ret);
void			arg_putnbr(t_curr *flag, va_list args, int *ret);
void			print_value_d(t_curr *flag, int n, int swap, int *to_ret);
void			reset_struct(t_curr *flag);
void			ft_putchar(char c);

#endif
