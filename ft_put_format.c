#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s, size_t byte)
{
	byte = ft_strlen(s);
	if (s != NULL)
		write(1, s, byte);
	return (byte);
}

size_t	ft_putnbr_int(int n, size_t byte)
{
	char	x;

	if (n < 0 && n > -10)
	{
		write(1, "-", 1);
		byte++;
	}
	if (n >= 10 || n <= -10)
	{
		byte += ft_putnbr_int(n / 10, byte);
		n %= 10;
	}
	if (n >= 0)
		x = '0' + n;
	else
		x = '0' - n;
	write(1, &x, 1);
	byte++;
	return (byte);
}

size_t	ft_putaddr(unsigned int addr, size_t byte)
{
	byte = ft_putnbr_base((int)addr, 16U, byte);
	return (byte);
}

size_t	ft_putnbr_base(int n, unsigned int base, size_t byte)
{
	(void)n;
	(void)base;
	return (byte);
}


size_t	ft_put_format(const char *format, va_list ptr)
{
	size_t byte;

	byte = 0;
	format++;
	if (*format == 'c')
		byte = ft_putchar(*format);
	else if (*format == 's')
		byte = ft_putstr(va_arg(ptr, char *), 0);
	else if (*format == 'p')
		byte = ft_putaddr(va_arg(ptr, void *), 0);
	else if (*format == 'd' || *format == 'i')
		byte = ft_putnbr_base(va_arg(ptr, int), 10U, 0);
	else if (*format == 'u')
		byte = ft_putnbr_int(va_arg(ptr, unsigned int), 0);
	else if (*format == 'x' || *format == 'X')
		byte = ft_putnbr_base(va_arg(ptr, int), 16U, 0);
	else if (*format == '%')
		byte = ft_putchar(*format);
	else
		byte = ft_putchar(*format);
	return (byte);
}
