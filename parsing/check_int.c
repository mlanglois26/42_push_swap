/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:05:57 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/07 12:25:01 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_overflow(long final_result)
{
	double	d;

	d = 18446744073709551615.0;
	if (final_result >= (long)d)
		return (1);
	if (final_result < -2147483648 || final_result > 2147483647)
		return (1);
	return (0);
}

long	ft_atol_and_check(char *nptr)
{
	long	res;
	long	final_result;
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
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	final_result = sign * res;
	if (is_overflow(final_result))
		return (2000000000000000);
	return (final_result);
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
