/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:28:05 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/15 16:33:34 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*temp;
	int	top;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	temp = (int *)malloc(sizeof(*temp) * (max - min));
	if (temp == NULL)
		return (-1);
	else
	{
		i = 0;
		top = max - min;
		while (i < top)
		{
			temp[i] = min + i;
			i++;
		}
		*range = temp;
		return (i);
	}
}
