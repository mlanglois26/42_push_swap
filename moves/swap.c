/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:16:32 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:33 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list *list_a)
{
	t_node	*first;
	t_node	*second;

	first = list_a->start;
	second = list_a->start->next;
	first->next = second->next;
	second->next = first;
	list_a->start = second;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *list_b)
{
	t_node	*first;
	t_node	*second;

	first = list_b->start;
	second = list_b->start->next;
	first->next = second->next;
	second->next = first;
	list_b->start = second;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list *list_a, t_list *list_b)
{
	sa(list_a);
	sb(list_b);
	ft_putstr_fd("ss\n", 1);
}
