/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:46:37 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/13 10:39:51 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fonction pour trouver le plus petit noeud en fonction de sa valeur

t_node	*ft_find_smallest_node_value(t_node *current_node)
{
	t_node	*smallest_node;
	long	smallest_value;

	smallest_node = NULL;
	smallest_value = 2147483648;
	while (current_node != NULL)
	{
		if (current_node->index == -1 && current_node->value < smallest_value)
		{
			smallest_node = current_node;
			smallest_value = current_node->value;
		}
		current_node = current_node->next;
	}
	return (smallest_node);
}

// fonction pour assigner des index aux noeuds

static void	ft_assign_index(t_node *current_node)
{
	t_node	*tmp_smallest_node;
	int		index;

	index = 0;
	tmp_smallest_node = ft_find_smallest_node_value(current_node);
	while (tmp_smallest_node != NULL)
	{
		tmp_smallest_node->index = index++;
		tmp_smallest_node = ft_find_smallest_node_value(current_node);
	}
}

// fonction utilsiee dans generate_list pour que ma liste soit bien indexee

void	ft_assign_index_to_list(t_list *list_a)
{
	t_node	*current_node;

	current_node = list_a->start;
	while (current_node != NULL)
	{
		ft_assign_index(current_node);
		current_node = current_node->next;
	}
}
