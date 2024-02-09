/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:13:25 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:23 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// push vers a (prend node de b pour mettre dans a)

void	pa(t_list *list_a, t_list *list_b)
{
	t_node	*first_of_b;

	if (list_b->start == NULL)
		return ;
	first_of_b = list_b->start;
	list_b->start = first_of_b->next;
	first_of_b->prev = NULL;
	first_of_b->next = list_a->start;
	list_a->start = first_of_b;
	list_b->len--;
	list_a->len++;
	ft_putstr_fd("pa\n", 1);
}

// push vers b (prend node de a pour mettre dans b)

void	pb(t_list *list_a, t_list *list_b)
{
	t_node	*first_of_a;

	if (list_a->start == NULL)
		return ;
	first_of_a = list_a->start;
	list_a->start = first_of_a->next;
	first_of_a->prev = NULL;
	first_of_a->next = list_b->start;
	list_b->start = first_of_a;
	list_b->len++;
	list_a->len--;
	ft_putstr_fd("pb\n", 1);
}
