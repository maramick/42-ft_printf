#include "ft_printf.h"

int	main(void)
{
	char	str[100] = "Phanuwat";
	//int		n = -123123443;

	(void)str;

	////my ft_printf////
	printf("->my_printf : %d\n", ft_printf("%c", 'c'));
	//printf("->my_printf : %d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	////////////////////

	////or ft_printf////
	printf("->my_printf : %d\n", ft_printf("%c", 'c'));
	//printf("->or_printf : %d\n", printf("\001\002\007\v\010\f\r\n"));
	////////////////////
	printf("\n\n\n\n");
	return (0);
}
