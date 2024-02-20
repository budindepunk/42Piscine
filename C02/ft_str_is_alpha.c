/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:23:32 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:59:02 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A')
			return (0);
		else if (str[i] > 'Z' && str[i] < 'a')
			return (0);
		else if (str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
