/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:35:45 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/18 18:46:06 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

int	read_one_line(int fd, char *line)
{
	int		bytes_read;
	char	bufferito[1];

	read(fd, bufferito, 1);
	line[0] = bufferito[0];
	bytes_read = 1;
	while (bufferito[0] != '\n') 
	{
		if (read(fd, bufferito, 1) == 1)
		{
			line[bytes_read] = bufferito[0];
			bytes_read++;
		}
		else
			return (0);
	}
	return (bytes_read);
}

int	is_alpha(char c)
{
	if (c < 'A' || c > 'z')
		return (0);
	if (c > 'Z' && c < 'a')
		return (0);
	if (c == ' ')
		return (0);
	return (1);
}

void	extract_value(char *line, int line_length, int start, char *value)
{
	int	index_counter;
	int	j;

	index_counter = 0;
	j = start;
	while (j < line_length - 1)
	{
		if (!is_alpha(line[j]))
			j++;
		if (is_alpha(line[j]))
		{
			value[index_counter] = line[j];
			j++;
			index_counter++;
		}
	}
	value[index_counter] = '\0';
}

int	parse_line(char *line, int line_length, char *key, char *value)
{
	int	index_counter;
	int	count;
	int	j;

	index_counter = 0;
	count = 0;
	j = 0;
	while (line[j] != ':')
	{
		if (line[j] == ' ')
			j++;
		if (line[j] <= '9' && line[j] >= '0')
		{
			key[index_counter] = line[j];
			count++;
			j++;
			index_counter++;
		}
	}
	key[index_counter] = '\0';
	extract_value(line, line_length, j, value);
	return (count);
}

void	read_dictionary(int fd, char **tens, char **smalls, char **big_boys)
{
	int		line_length;
	char	line[150];
	char	*extracted_value;
	char	*extracted_key;
	int		count;

	while (1) 
	{
		line_length = read_one_line(fd, line);
		if (line_length == 1)
			continue ;
		if (line_length == 0)
			break ;
		extracted_key = (char *)malloc(30);
		extracted_value = (char *)malloc(40);
		count = parse_line(line, line_length, extracted_key, extracted_value);
		if (count <= 3)
			handle_pairs(extracted_key, extracted_value, smalls, tens);
		if (count > 3)
			big_boys[count / 3] = extracted_value;
	}
}
