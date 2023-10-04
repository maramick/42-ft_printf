#include "ft_printf.h"

// int LargestNumber(int n, ...)
// {
// 	va_list ptr;

// 	va_start(ptr, n);

// 	int max = va_arg(ptr, int);

// 	for (int i = 0; i < n-1; i++) {
// 		int temp = va_arg(ptr, int);
// 		max = temp > max ? temp : max;
// 	}
// 	va_end(ptr);
// 	return max;
// }
// int main()
// {
// 	printf("\n\n Variadic functions: \n");
// 	printf("\n %d ", LargestNumber(2, 1, 2));
// 	printf("\n %d ", LargestNumber(3, 3, 4, 5));

// 	printf("\n %d ", LargestNumber(4, 6, 7, 8, 9));

// 	printf("\n");

// 	return 0;
// }
