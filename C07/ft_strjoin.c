#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (des[len])
		len++;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	length;
	char	*new;

	i = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += (ft_strlen(sep) * (size - 1));
	new = (char *)malloc(length);
	i = 0;
	while (i < size)
	{
		new = ft_strcat(new, strs[i]);
		if (i < size - 1)
			new = ft_strcat(new, sep);
		i++;
	}
	return (new);
}
