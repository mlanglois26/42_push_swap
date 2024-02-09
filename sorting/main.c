/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:06:51 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/05 15:28:11 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_list(t_list *list)
{
	t_node	*current;

	current = list->start;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_free_lists(t_list *list_a, t_list *list_b)
{
	t_node	*current;
	t_node	*tmp;

	current = list_a->start;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(list_a);
	current = list_b->start;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		exit(0);
	else
	{
		list_a = ft_generate_list(argc, argv);
		list_b = ft_init_list();
		if (list_a == NULL)
			ft_putstr_fd("Error\n", 2);
		else
		{
			if (is_sorted_list(list_a))
				return (ft_free_lists(list_a, list_b), 0);
			else
			{
				ft_select_sort(list_a, list_b);
				ft_free_lists(list_a, list_b);
			}
		}
	}
	return (0);
}
