/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:36 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/21 15:32:57 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_length(int size, char **strs, char *sep)
{
	int	length;
	int	i;

	if (size == 1)
		return (ft_strlen(strs[0]));
	length = 0;
	i = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += (ft_strlen(sep) * (size - 1));
	return (length);
}

int	ft_assign_value(char *str1, char *str2, int len)
{
	int	j;

	j = 0;
	while (str2[j])
	{
		str1[len] = str2[j];
		len++;
		j++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = get_length(size, strs, sep);
	if (size > 0)
	{
		str = (char *)malloc((len) + 1 * sizeof(char));
		len = 0;
		while (i < size)
		{
			len = ft_assign_value(str, strs[i], len);
			if (i < size -1)
				len = ft_assign_value(str, sep, len);
			i++;
		}
		str[len] = '\0';
	}
	else
		str = (char *)malloc(1 * sizeof(char));
	return (str);
}
