/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:04:30 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/07 12:20:18 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* structures */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	unsigned int	len;
	t_node			*start;
	t_node			*end;
}					t_list;

/* utils */

void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);

/* parsing - check cases & error */

int					ft_check_char_ok(char *argv);
long				ft_atol_and_check(char *nptr);
int					has_duplicate(int *data, int size);
void				ft_error(void);
int					is_overflow(long final_result);

/* parsing - fonctions */

int					*ft_handle_nb_of_args_and_convert_char_to_int(int argc,
						char **argv, int *size);
t_list				*ft_generate_list(int argc, char **argv);

/* init */

t_list				*ft_init_list(void);
t_node				*ft_init_node(int *nb);
void				ft_fill_list(t_list *list, int *nb);

/* indexation */

void				ft_assign_index_to_list(t_list *list_a);
t_node				*ft_find_smallest_node(t_node *current_node);

/* moves */

void				pa(t_list *list_a, t_list *list_b);
void				pb(t_list *list_a, t_list *list_b);

void				sa(t_list *list_a);
void				sb(t_list *list_b);
void				ss(t_list *list_a, t_list *list_b);

void				ra(t_list *list_a);
void				rb(t_list *list_b);
void				rr(t_list *list_a, t_list *list_b);

void				rra(t_list *list_a);
void				rrb(t_list *list_b);
void				rrr(t_list *list_a, t_list *list_b);

/* sort utils */

t_node				*ft_find_biggest_node_value(t_list *list);
int					ft_count_bits(int n);

/* sort */

void				ft_radix_binary_sort(t_list *list_a, t_list *list_b);
void				ft_sort_for_three(t_list *list_a);
void				ft_general_sort_for_four(t_list *list_a, t_list *list_b);
void				ft_sort_for_five(t_list *list_a, t_list *list_b);
void				ft_mix_four(t_list *list_a, t_list *list_b);

void				ft_cas_a_part_1(t_list *list_a);
void				ft_cas_a_part_2(t_list *list_a);
void				ft_cas_a_part_3(t_list *list_a);
void				ft_cas_a_part_4(t_list *list_a);
void				ft_cas_a_part_5(t_list *list_a);

/* simple sort */
void				ft_first_part_for_four(t_list *list_a, t_list *list_b);
void				ft_second_part_for_four(t_list *list_a, t_list *list_b);

/* main */

void				ft_select_sort(t_list *list_a, t_list *list_b);
int					is_sorted_list(t_list *list);
void				ft_free_lists(t_list *list_a, t_list *list_b);

void				ft_free_split(char **str);
void				ft_error_split(int argc, char **argv);

#endif
