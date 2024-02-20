/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:43:17 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/05 19:53:13 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	diff;
	int	c;

	diff = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if (c >= 'A' && c <= 'Z')
				str[i] = str[i] + diff;
			if (str[i - 1] < '0' || str[i - 1] > 'z')
				str[i] = str[i] - diff;
			else if (str[i - 1] > 'Z' && str[i - 1] < 'a')
				str[i] = str[i] - diff;
			else if (str[i - 1] > '9' && str[i - 1] < 'A')
				str[i] = str[i] - diff;
			else if (i == 0)
				str[i] = str[i] - diff;
		}
		i++;
	}
	return (str);
}
