/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:02 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:26 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// on veut que le dernier devienne le premier

void	rra(t_list *list_a)
{
	t_node	*original_last_node;

	if (list_a->start == NULL || list_a->start == list_a->end)
		return ;
	original_last_node = list_a->end;
	list_a->end = original_last_node->prev;
	list_a->end->next = NULL;
	original_last_node->prev = NULL;
	original_last_node->next = list_a->start;
	list_a->start->prev = original_last_node;
	list_a->start = original_last_node;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list *list_b)
{
	t_node	*original_last_node;

	if (list_b->start == NULL || list_b->start == list_b->end)
		return ;
	original_last_node = list_b->end;
	list_b->end = original_last_node->prev;
	list_b->end->next = NULL;
	original_last_node->prev = NULL;
	original_last_node->next = list_b->start;
	list_b->start->prev = original_last_node;
	list_b->start = original_last_node;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list *list_a, t_list *list_b)
{
	rra(list_a);
	rrb(list_b);
	ft_putstr_fd("rrr\n", 1);
}
