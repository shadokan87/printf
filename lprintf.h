
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#ifndef LPRINTF_H
#ifndef DEC
#ifndef HEXD
# define DEC "0123456789"
# define HEXD "0123456789abcdef"
# define MAJHEXD "0123456789ABCDEF"
# define LPRINTF_H
# define STAR '*'
# define DASH '-'
# define ZERO '0'

int	ft_atoi(char *str);
int	ft_nbrlen(int n);
int	ft_strlen(char *str);
int	ft_printf(const char *str, ...);
int	is_hidden(char *str);
int	ft_isprint(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putptr(unsigned long int ptr);
void    ft_putchar_str(char **str, char c);
char    *ft_putnbr_base_u(unsigned int n, char *base);
char	*ft_putnbr_base(int n, char *base);
char	*ft_strrev(char *str);
char	*ft_strdup(const char *s1);
void	*ft_realloc(void *ptr, size_t size);
void	ft_memsub(void **dst, void *src, size_t index, int max);

#endif
#endif
#endif
