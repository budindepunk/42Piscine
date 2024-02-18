/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:29:04 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:35 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	handle_pairs(char *key, char *value, char **smalls, char **tens);

int		handle_block(int atoi_num, char **smalls, char **tens);

void	print_number(char *number, char **smalls, char **tens, char **big_boys);

char	*pad_number(char *number);

int		check_arguments(int argc, char *argv[]);

void	cleanup(char **smalls, char **tens, char **big_boys);

int		ft_atoi(char *str);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

char	*ft_strslice(char *str, int start, int end);

char	*ft_strcat(char *zeroes, char *src);

void	read_dictionary(int fd, char **tens, char **smalls, char **big_boys);

int		is_alpha(char c);

int		read_one_line(int fd, char *line);

void	extract_value(char *line, int line_length, int start, char *value);

int		parse_line(char *line, int line_length, char *key, char *value);
