/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:45:14 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/16 09:31:38 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  fonction pour initialiser la liste */

t_list	*ft_init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (list)
	{
		list->len = 0;
		list->start = NULL;
		list->end = NULL;
	}
	return (list);
}

/*  fonction pour initialiser le noeud a partir de l int */

t_node	*ft_init_node(int *nb)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	if (node)
	{
		node->value = *nb;
		node->index = -1;
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}

/*  fonction pour ajouter un noeud nouvellement creer a la liste */

void	ft_fill_list(t_list *list, int *nb)
{
	t_node	*new_node;

	new_node = ft_init_node(nb);
	if (list->len == 0)
	{
		list->start = new_node;
		list->end = new_node;
	}
	else
	{
		new_node->prev = list->end;
		list->end->next = new_node;
		list->end = new_node;
	}
	list->len++;
}
