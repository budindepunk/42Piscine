#include <stdio.h>

int	ft_is_prime(int	nb)
{
	int	i;

	if (nb == 0 || nb == 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int	nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

int	main(void)
{
	printf("%d\n", ft_find_next_prime());
	return (0);
}
