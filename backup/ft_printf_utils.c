#include "ft_printf.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
