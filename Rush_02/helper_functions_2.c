/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:08:40 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/18 20:24:54 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

void	handle_pairs(char *key, char *value, char **smalls, char **tens)
{
	int	atoi_key;

	atoi_key = ft_atoi(key);
	if (atoi_key <= 19)
		smalls[atoi_key] = value;
	else if (atoi_key <= 100 && atoi_key % 10 == 0)
		tens[atoi_key / 10] = value;
}

int	handle_block(int atoi_num, char **smalls, char **tens)

{
	if (atoi_num == 0)
		return (1);
	if (atoi_num >= 100)
	{
		ft_putstr(smalls[atoi_num / 100]);
		write(1, " ", 1);
		ft_putstr(tens[10]);
		if (atoi_num % 100 == 0)
			return (0);
		write(1, " and ", 5);
		atoi_num = atoi_num % 100;
	}
	if (atoi_num < 20)
		ft_putstr(smalls[atoi_num]);
	else
	{
		ft_putstr(tens[atoi_num / 10]);
		if (atoi_num % 10 == 0)
			return (0);
		write(1, "-", 1);
		ft_putstr(smalls[atoi_num % 10]);
	}
	return (0);
}

int	check_zero(char *number, char **smalls)
{
	int	j;

	j = 0;
	while (j < ft_strlen(number))
	{
		if (number[j] != '0')
			return (1);
		j++;
	}
	ft_putstr(smalls[0]);
	write(1, "\n", 1);
	return (0);
}
