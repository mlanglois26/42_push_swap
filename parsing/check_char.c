/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:05:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/22 10:51:27 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	is_valid_data(char *data)
{
	int	i;

	i = 0;
	if ((data[i] == '+' || data[i] == '-') && ft_isdigit(data[i + 1]))
		i++;
	while (data[i] != '\0')
	{
		if (!ft_isdigit(data[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_char_ok(char *argv)
{
	if (!(is_valid_data(argv)))
		return (0);
	return (1);
}
