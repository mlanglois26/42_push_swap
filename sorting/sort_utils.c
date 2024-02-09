/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:28:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/09 17:33:37 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fonction pour trouver le plus grand noeud en fonction de sa value

t_node	*ft_find_biggest_node_value(t_list *list)
{
	int		max_value;
	t_node	*current_node;
	t_node	*biggest_node;

	if (list == NULL || list->start == NULL)
		return (NULL);
	biggest_node = NULL;
	current_node = list->start;
	max_value = INT_MIN;
	while (current_node != NULL)
	{
		if (current_node->value > max_value)
		{
			max_value = current_node->value;
			biggest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (biggest_node);
}

// fonction pour calculer le nb de bits

int	ft_count_bits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n >>= 1;
		count++;
	}
	return (count);
}
