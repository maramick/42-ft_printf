#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

//////Deleted Header///////
# include <stdio.h>
//////////////////////////

size_t	ft_put_format(const char *format, va_list ptr);
size_t	ft_putnbr_base(int n, unsigned int base, size_t byte);
size_t	ft_putnbr_int(int n, size_t byte);
size_t	ft_putstr(char *s, size_t byte);
size_t	ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif
