/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:27 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/12 19:21:15 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* fonction pour sort liste de 3 */

static void	ft_first_part_for_three(t_list *list_a)
{
	t_node	*first_node;

	first_node = list_a->start;
	if (first_node->index == 0)
	{
		rra(list_a);
		sa(list_a);
	}
	else if ((first_node->index == 1) && (first_node->next->index == 2))
		rra(list_a);
}

static void	ft_second_part_for_three(t_list *list_a)
{
	t_node	*first_node;
	int		sorted;

	sorted = 0;
	first_node = list_a->start;
	while (!sorted)
	{
		sorted = 1;
		if (first_node->index == 1)
		{
			sa(list_a);
			sorted = 0;
		}
		if (first_node->index == 2)
		{
			ra(list_a);
			sorted = 0;
		}
		first_node = list_a->start;
	}
}

void	ft_sort_for_three(t_list *list_a)
{
	ft_first_part_for_three(list_a);
	if (!(is_sorted_list(list_a)))
		ft_second_part_for_three(list_a);
}

/* fonction pour sort liste de 4 - part 1 */

void	ft_mix_four(t_list *list_a, t_list *list_b)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = list_a->start;
	last_node = list_a->end;
	if (first_node->index == 0 && first_node->next->index == 1
		&& last_node->index == 2)
		ft_cas_a_part_1(list_a);
	else if (first_node->index == 1 && first_node->next->index == 0
		&& last_node->index == 2)
		ft_cas_a_part_2(list_a);
	else if (first_node->index == 2 && first_node->next->index == 1
		&& last_node->index == 0)
		ft_cas_a_part_3(list_a);
	else if (first_node->index == 1 && first_node->next->index == 2
		&& last_node->index == 0)
		rra(list_a);
	else if (first_node->index == 0 && first_node->next->index == 2
		&& last_node->index == 1)
		ft_cas_a_part_4(list_a);
	else if (first_node->index == 2 && first_node->next->index == 0
		&& last_node->index == 1)
		ft_cas_a_part_5(list_a);
	else
		ft_general_sort_for_four(list_a, list_b);
}

void	ft_general_sort_for_four(t_list *list_a, t_list *list_b)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = list_a->start;
	last_node = list_a->end;
	if (first_node->next->index == 3)
	{
		ra(list_a);
		pb(list_a, list_b);
	}
	if (first_node->index == 3)
		pb(list_a, list_b);
	if (last_node->index == 3)
	{
		rra(list_a);
		pb(list_a, list_b);
	}
	first_node = list_a->start;
	if (!(is_sorted_list(list_a)))
		ft_sort_for_three(list_a);
	pa(list_a, list_b);
	ra(list_a);
}
