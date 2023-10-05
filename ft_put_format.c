#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s, size_t byte)
{
	if (s)
		byte = ft_strlen(s);
	else if (!s)
	{
		byte = 6;
		write(1, "(null)", byte);
	}
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

size_t	ft_putnbr_unsigned_int(unsigned int n, size_t byte)
{
	char	x;

	if (n >= 10)
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

size_t	ft_putnbr_base(unsigned int n, char format, size_t byte)
{
	char buffer[100];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 16) + '0';
		if (n % 16 >= 10)
		{
			buffer[i - 1] += 7;
		}
		n /= 16;
	}
	buffer[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'Z' && format == 'x')
			buffer[i] = buffer[i] + 32;
		write(1, &buffer[i], 1);
		byte++;
		//printf("byte: %zu buffer: %d", byte, buffer[i]);
		i--;
	}
	return (byte);
}

size_t	ft_put_format(const char *format, va_list ptr)
{
	size_t	byte;
	char	buf;

	byte = 0;
	format++;
	if (*format == 'c')
	{
		buf = (char)va_arg(ptr, char *);
		byte = ft_putchar(buf);
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
		byte = ft_putstr("%", 0);
	else
		byte = ft_putchar(*format);
	return (byte);
}
