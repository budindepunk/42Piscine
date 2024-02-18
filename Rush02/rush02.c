/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:26 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/18 19:02:21 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

void	print_number(char *number, char **smalls, char **tens, char **big_boys)
{
	int	i;
	int	c;
	int	atoi_block;
	int	skip_intermezzo;

	i = 0;
	skip_intermezzo = 1;
	c = ft_strlen(number) / 3 - 1;
	while (i < ft_strlen(number) - 2)
	{
		if (!skip_intermezzo)
			write(1, ", ", 2);
		atoi_block = ft_atoi(ft_strslice(number, i, i + 2));
		skip_intermezzo = handle_block(atoi_block, smalls, tens);
		if (!skip_intermezzo && c != 0)
		{
			write(1, " ", 1);
			ft_putstr(big_boys[c]);
		}
		c--;
		i += 3;
	}
	write(1, "\n", 1);
}

char	*pad_number(char *number)
{
	if (ft_strlen(number) % 3 == 1)
		return (ft_strcat("00", number));
	else if (ft_strlen(number) % 3 == 2)
		return (ft_strcat("0", number));
	return (number);
}

int	check_arguments(int argc, char *argv[])
{
	int	i;

	if (argc < 2 || argv[1][0] == '-')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2 && ft_strlen(argv[1]) >= 40)
	{
		write(1, "Dict Error\n", 12);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (is_alpha(argv[1][i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	cleanup(char **smalls, char **tens, char **big_boys)
{
	int	j;

	j = 0;
	while (j < 20)
	{
		free(smalls[j]);
		j++;
	}
	j = 2;
	while (j < 11)
	{
		free(tens[j]);
		j++;
	}
	j = 1;
	while (j < 13)
	{
		free(big_boys[j]);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*number;
	char	*tens[11];
	char	*smalls[20];
	char	*big_boys[13];

	if (!check_arguments(argc, argv))
		return (0);
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		number = argv[2];
	}
	else
	{
		fd = open("numbers.dict", O_RDONLY);
		number = argv[1];
	}
	read_dictionary(fd, tens, smalls, big_boys);
	close(fd);
	print_number(pad_number(number), smalls, tens, big_boys);
	cleanup(smalls, tens, big_boys);
	return (0);
}
