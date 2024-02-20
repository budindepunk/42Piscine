/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:37 by csilva-r          #+#    #+#             */
/*   Updated: 2024/02/14 13:11:18 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	result = nb;
	if (nb == 0 && power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
