int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	if (nb == 0)
		return (1);
	else
	{
		while (i <= nb)
		{
			result = result * i;
			i++;
		}
	}
	return (result);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(5));
	printf("%d\n", ft_iterative_factorial(4));
	return (0);
}