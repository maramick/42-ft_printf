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

size_t	ft_putaddr(unsigned long addr, size_t byte)
{
	char buffer[100];
	int i = 0;

	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (addr > 0)
	{
		buffer[i++] = (addr % 16) + '0';
		if (addr % 16 >= 10) {
			buffer[i - 1] += 7;
		}
		addr /= 16;
	}
	buffer[i] = '\0';

	write(1, "0x", 2);
	byte += 2;
	i--;
	while (i >= 0)
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			buffer[i] = buffer[i] + 32;
		write(1, &buffer[i], 1);
		byte++;
		i--;
	}
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
		byte = ft_putaddr((uintptr_t)va_arg(ptr, void *), 0);
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
