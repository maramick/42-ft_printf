#include "ft_printf.h"

//va_list is the ptr to the last fix arg in variadic function
//va_start choose the pointer to the last fix arg in variadic function
//And then enable to access argument in variadic function
	//first arg is the pointer in va_list
	//second arg is last fix arg in variadic function
//va_arg access the argument
	//first arg is the pointer in va_list
	//second arg is data type to be cast to argument
//va_end end the traversal in variadic function argument

// Format to be handle
// You have to implement the following conversions:
// 1 %c Prints a single character.
// 2 %s Prints a string (as defined by the common C convention).
// 3 %p The void * pointer argument has to be printed in hexadecimal format.
// 4 %d Prints a decimal (base 10) number.
// 5 %i Prints an integer in base 10.
// 6 %u Prints an unsigned decimal (base 10) number.
// 7 %x Prints a number in hexadecimal (base 16) lowercase format.
// 8 %X Prints a number in hexadecimal (base 16) uppercase format.
// 9 %% Prints a percent sign.

//printf//
int	printf_(const char *format, va_list ptr)
{
	size_t	byte;

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

int	main(void)
{
	char	str[100] = "Phanuwat";
	//int		n = -123123443;

	(void)str;

	////my ft_printf////
	printf("->my_printf : %d\n", ft_printf("%p \n%s", str, str));
	////////////////////

	////or ft_printf////
	printf("->or_printf : %d\n", printf("%p \n%s", str, str));
	////////////////////
	return (0);
}
