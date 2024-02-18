#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int 	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	num = 0;
	i = 0;
	while (str[i] <= ' ')
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
	i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	    ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strslice(char *str, int start, int end)
{
    int      i;
	char	*new;    

    new = (char *)malloc(end - start + 2);
    i = 0;
    while (i <= end - start)
    {
        new[i] = str[start + i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char	*ft_strcat(char *zeroes, char *src)
{
	int i;
	int j;
    char *new;

	i = 0;
	j = 0;
    new = (char *)malloc(ft_strlen(zeroes) + ft_strlen(src));
	while (zeroes[j] != '\0')
    {
        new[j] = zeroes[j];
		j++;
    }
	while (src[i] != '\0')
	{
		new[j] = src[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}