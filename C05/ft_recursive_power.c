#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (nb * ft_recursive_power(nb, power - 1)); 
}

int	main(void)
{
	printf("%d\n", ft_recursive_power(2, 3));
	printf("%d\n", ft_recursive_power(1, 9));
	printf("%d\n", ft_recursive_power(5, 2));
	return (0);
}
