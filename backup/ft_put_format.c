#include "ft_printf.h"

ssize_t	ft_putchar(char *c, ssize_t byte)
{
	if(write(1, c, byte) < 0)
		return (-1);
	return (byte);
}

ssize_t	ft_putstr(char *s, ssize_t byte)
{
	if (s)
		byte = ft_putchar(s, ft_strlen(s));
	else if (!s)
	{
		byte = 6;
		if(write(1, "(null)", byte) < 0)
			return (-1);
	}
	return (byte);
}

ssize_t	ft_putnbr_int(int n, ssize_t byte)
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

ssize_t	ft_putnbr_unsigned_int(unsigned int n, ssize_t byte)
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

ssize_t	ft_putaddr(unsigned long addr, ssize_t byte)
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

ssize_t	ft_putnbr_base(unsigned int n, char format, ssize_t byte)
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
		i--;
	}
	return (byte);
}

