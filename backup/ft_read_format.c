#include "ft_printf.h"

ssize_t	ft_put_format(const char *format, va_list ptr)
{
	ssize_t	byte;
	char	buf;

	byte = 0;
	format++;
	if (*format == 'c')
	{
		buf = va_arg(ptr, int);
		byte = ft_putchar(&buf, 1);
	}
	else if (*format == 's')
		byte = ft_putstr(va_arg(ptr, char *), 0);
	else if (*format == 'p')
		byte = ft_putaddr((uintptr_t)va_arg(ptr, void *), 0);
	else if (*format == 'd' || *format == 'i')
		byte = ft_putnbr_int(va_arg(ptr, signed int), 0);
	else if (*format == 'u')
		byte = ft_putnbr_unsigned_int(va_arg(ptr, unsigned int), 0);
	else if (*format == 'x' || *format == 'X')
		byte = ft_putnbr_base(va_arg(ptr,unsigned int), *format, 0);
	else if (*format == '%')
		byte = write(1, "%", 1);
	else
		byte = write(1, &format, 1);
	return (byte);
}
