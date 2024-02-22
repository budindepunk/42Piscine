/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:43:38 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/07 16:14:23 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	difference;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i])
	{
		if ((unsigned int)i == n - 1 || s1[i] == '\0')
			return (0);
		i++;
	}
	difference = s1[i] - s2[i];
	return (difference);
}
