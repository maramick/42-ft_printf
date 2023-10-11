#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

//////Deleted Header///////
# include <stdio.h>
//////////////////////////

ssize_t	ft_put_format(const char *format, va_list ptr);
ssize_t	ft_putnbr_unsigned_int(unsigned int n, ssize_t byte);
ssize_t	ft_putnbr_base(unsigned int n, char format, ssize_t byte);
ssize_t	ft_putaddr(unsigned long addr, ssize_t byte);
ssize_t	ft_putnbr_int(int n, ssize_t byte);
ssize_t	ft_putstr(char *s, ssize_t byte);
ssize_t	ft_putchar(char *c, ssize_t byte);
ssize_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);

#endif
