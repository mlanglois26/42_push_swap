/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:16:01 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:30 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// on veut que le premier devienne le dernier

void	ra(t_list *list_a)
{
	t_node	*original_first_node;

	if (list_a->start == NULL || list_a->start == list_a->end)
		return ;
	original_first_node = list_a->start;
	list_a->start = original_first_node->next;
	list_a->start->prev = NULL;
	original_first_node->next = NULL;
	original_first_node->prev = list_a->end;
	list_a->end->next = original_first_node;
	list_a->end = original_first_node;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list *list_b)
{
	t_node	*original_first_node;

	if (list_b->start == NULL || list_b->start == list_b->end)
		return ;
	original_first_node = list_b->start;
	list_b->start = original_first_node->next;
	list_b->start->prev = NULL;
	original_first_node->next = NULL;
	original_first_node->prev = list_b->end;
	list_b->end->next = original_first_node;
	list_b->end = original_first_node;
	ft_putstr_fd("ra\n", 1);
}

void	rr(t_list *list_a, t_list *list_b)
{
	ra(list_a);
	rb(list_b);
	ft_putstr_fd("rr\n", 1);
}
