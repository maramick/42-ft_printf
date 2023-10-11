#include "ft_printf.h"

/*This is for %c*/
ssize_t	ft_putchar(char *c)
{
	return (write(1, c, 1));
}

/*This is for %s*/
ssize_t	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

ssize_t ft_putnb_hex(unsigned long addr, char format, ssize_t byte, int check)
{
	if (check == -1)
		return (-1);
	if (addr > 15)
	{
		byte += ft_putnb_hex(addr / 16, format, byte, 1);
		if (byte == -1)
			return (-1);
	}
	if (format == 'x')
		check = write(1, &"0123456789abcdef"[addr % 16], 1);
	else if (format == 'X')
		check = write(1, &"0123456789ABCDEF"[addr % 16], 1);
	if (check == -1)
		return (-1);
	byte += 1;
	return (byte);
}

/*This is for %p*/
ssize_t ft_putnb_addr(unsigned long addr, ssize_t byte, int check)
{
	if (check == -1)
		return (-1);
	if (addr > 15)
		byte += ft_putnb_addr(addr / 16, byte, 1);
	check = write(1, &"0123456789abcdef"[addr % 16], 1);
	if (check == -1)
		return (-1);
	byte += 1;
	return (byte);
}
/*This is for %p*/
ssize_t	ft_putaddr(unsigned long addr, ssize_t byte)
{
	if (addr == 0)
		return (write(1, "0x0", 3));
	else if (ft_putstr("0x") == -1)
		return (-1);
	byte = ft_putnb_addr(addr, 0, 0);
	if (byte != -1)
		byte += 2;
	return (byte);
}

/*This is for %d & %i*/
ssize_t	ft_putnbr_signed(int n, ssize_t byte, int check)
{
	char	x;

	if (check == -1)
		return (-1);
	if (n < 0 && n > -10)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		byte++;
	}
	if (n >= 10 || n <= -10)
	{
		byte += ft_putnbr_signed(n / 10, byte, 1);
		if (byte == -1)
			return (-1);
		n %= 10;
	}
	if (n >= 0)
		x = '0' + n;
	else
		x = '0' - n;
	if (write(1, &x, 1) == -1)
		return (-1);
	byte++;
	return (byte);
}

/*This is for %u*/
ssize_t	ft_putnbr_unsigned(unsigned int n, ssize_t byte, int check)
{
	char	x;

	if (check == -1)
		return (-1);
	if (n >= 10)
	{
		byte += ft_putnbr_unsigned(n / 10, byte, 0);
		if (byte == -1)
			return (-1);
		n %= 10;
	}
	if (n >= 0)
		x = '0' + n;
	else
		x = '0' - n;
	if (write(1, &x, 1) == -1)
		return (-1);
	byte++;
	return (byte);
}

ssize_t	ft_put_format(const char *format, va_list ptr)
{
	char	buf;

	format++;
	if (*format == 'c')
	{
		buf = va_arg(ptr, int);
		return (ft_putchar(&buf));
	}
	else if (*format == 's')
		return ft_putstr(va_arg(ptr, char *));
	else if (*format == 'p')
		return ft_putaddr((uintptr_t)va_arg(ptr, void *), 0);
	else if (*format == 'd' || *format == 'i')
		return ft_putnbr_signed(va_arg(ptr, signed int), 0, 1);
	else if (*format == 'u')
		return ft_putnbr_unsigned(va_arg(ptr, unsigned int), 0, 1);
	else if (*format == 'x' || *format == 'X')
		return ft_putnb_hex(va_arg(ptr,unsigned int), *format, 0, 1);
	else if (*format == '%')
		return write(1, "%", 1);
	else
		return write(1, &format, 1);
}
