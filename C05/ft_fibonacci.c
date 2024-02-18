#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(void)
{
	// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...
	printf("%d\n", ft_fibonacci(15));
	return (0);
}