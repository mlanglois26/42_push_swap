/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:05:57 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/09 18:38:17 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_overflow(long final_result)
{
	if (final_result < -2147483648 || final_result > 2147483647)
		return (1);
	return (0);
}

long	ft_atol_and_check(char *nptr)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (is_overflow(sign * res))
			return (2000000000000000);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (is_overflow((double)(res)*sign))
		return (2000000000000000);
	return (res * sign);
}

int	has_duplicate(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
