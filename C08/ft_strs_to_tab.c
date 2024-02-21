/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:39 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/21 17:24:32 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*new;

	len = 0;
	while (src[len])
		len++;
	new = (char *)malloc(len + 1);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*par;
	int				i;

	par = malloc(sizeof(t_stock_str) * (ac + 1));
	if (par == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		par[i].str = av[i];
		par[i].copy = ft_strdup(av[i]);
		par[i].size = ft_strlen(av[i]);
		i++;
	}
	par[i].str = 0;
	return (par);
}
