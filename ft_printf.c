#include "ft_printf.h"

int	printf_(const char *format, va_list ptr)
{
	ssize_t	byte;

	byte = 0;
	while(*format)
	{
		if (*format == '%')
		{
			byte += ft_put_format(format, ptr);
			format += 2;
		}
		else
		{
			byte += ft_putchar(*format);
			format += 1;
		}
	}
	return ((int)byte);
}

int	ft_printf(const char *format, ...)
{
	va_list ptr;
	int	ret;

	//NULL error handle//
	if (!format)
		return (-1);
	/////////////////////

	va_start(ptr, format);
	ret = printf_(format, ptr);
	va_end(ptr);

	return (ret);
}


