/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:10:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/12 19:31:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_combo_for_five_1(t_list *list_a, t_list *list_b)
{
	ra(list_a);
	pb(list_a, list_b);
}

static void	ft_combo_for_five_2(t_list *list_a, t_list *list_b)
{
	rra(list_a);
	rra(list_a);
	pb(list_a, list_b);
}

static void	ft_combo_for_five_3(t_list *list_a, t_list *list_b)
{
	rra(list_a);
	pb(list_a, list_b);
}

static void	ft_combo_for_five_4(t_list *list_a, t_list *list_b)
{
	ra(list_a);
	sa(list_a);
	pb(list_a, list_b);
}

void	ft_sort_for_five(t_list *list_a, t_list *list_b)
{
	t_list	*saved;
	t_node	*first_node;
	t_node	*last_node;

	saved = list_a;
	saved->start = list_a->start;
	first_node = saved->start;
	last_node = saved->end;
	if (first_node->next->index == 4)
		ft_combo_for_five_1(list_a, list_b);
	else if (first_node->index == 4)
		pb(list_a, list_b);
	else if (last_node->prev->index == 4)
		ft_combo_for_five_2(list_a, list_b);
	else if (last_node->index == 4)
		ft_combo_for_five_3(list_a, list_b);
	else
		ft_combo_for_five_4(list_a, list_b);
	first_node = list_a->start;
	saved = list_a;
	saved->start = list_a->start;
	if (!(is_sorted_list(list_a)))
		ft_mix_four(list_a, list_b);
	pa(list_a, list_b);
	ra(list_a);
}
