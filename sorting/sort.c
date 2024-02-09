/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:17:45 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/13 11:07:15 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_select_sort(t_list *list_a, t_list *list_b)
{
	if (list_a->len == 3)
		ft_sort_for_three(list_a);
	else if (list_a->len == 5)
		ft_sort_for_five(list_a, list_b);
	else
		ft_radix_binary_sort(list_a, list_b);
}

void	ft_algo(t_list *list_a, t_list *list_b, t_list *saved_list, int max_bit)
{
	int	i;
	int	j;
	int	size;
	int	last_bit;

	size = saved_list->len;
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j++ < size)
		{
			saved_list->start = list_a->start;
			last_bit = (saved_list->start->index >> i) & 1;
			if (last_bit == 1)
				ra(list_a);
			else
				pb(list_a, list_b);
		}
		while (list_b->len != 0)
			pa(list_a, list_b);
		i++;
	}
}

void	ft_radix_binary_sort(t_list *list_a, t_list *list_b)
{
	t_list	*saved_list;
	t_node	*biggest_node;
	int		max_simplify_nb;
	int		max_bit;

	biggest_node = ft_find_biggest_node_value(list_a);
	max_simplify_nb = biggest_node->index;
	max_bit = ft_count_bits(max_simplify_nb);
	saved_list = list_a;
	saved_list->start = list_a->start;
	ft_algo(list_a, list_b, saved_list, max_bit);
}
