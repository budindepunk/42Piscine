#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
	return (0);
}
