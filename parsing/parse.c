/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:08:01 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/22 10:50:11 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// c est pour gerer le split et degager le ./out

static char	**ft_handle_nb_of_args(int argc, char **argv)
{
	char	**args_to_evaluate;

	if (argc == 2)
		args_to_evaluate = ft_split(argv[1], ' ');
	else
		args_to_evaluate = argv + 1;
	if (!args_to_evaluate)
	{
		if (argc == 2)
			ft_free_split(args_to_evaluate);
		return (NULL);
	}
	return (args_to_evaluate);
}

// gere les valgrind en fonction du nb d args et call ft_error

static void	ft_free_and_call_ft_error(int argc, char **args_to_evaluate,
		int *int_to_evaluate)
{
	if (argc == 2)
		ft_free_split(args_to_evaluate);
	free(int_to_evaluate);
	ft_error();
}

// c est pour renvoyer des int qui ont passe tous les tests et free si error

static int	*ft_convert_char_to_int(int argc, char **args_to_evaluate, int size)
{
	int	*int_to_evaluate;
	int	i;

	int_to_evaluate = (int *)malloc(sizeof(int) * size);
	if (!int_to_evaluate)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!ft_check_char_ok(args_to_evaluate[i]))
			ft_free_and_call_ft_error(argc, args_to_evaluate, int_to_evaluate);
		int_to_evaluate[i] = ft_atol_and_check(args_to_evaluate[i]);
		if (ft_atol_and_check(args_to_evaluate[i]) == 2000000000000000)
			ft_free_and_call_ft_error(argc, args_to_evaluate, int_to_evaluate);
		i++;
	}
	if (has_duplicate(int_to_evaluate, i))
		ft_free_and_call_ft_error(argc, args_to_evaluate, int_to_evaluate);
	return (int_to_evaluate);
}

// fonction principale qui regroupe nb_of_argv et convert_char_to_int

int	*ft_handle_nb_of_args_and_convert_char_to_int(int argc, char **argv,
		int *size)
{
	char	**args_to_evaluate;
	int		*int_to_evaluate;
	int		i;

	args_to_evaluate = ft_handle_nb_of_args(argc, argv);
	if (!args_to_evaluate)
		return (NULL);
	i = 0;
	while (args_to_evaluate[i] != NULL)
		i++;
	*size = i;
	int_to_evaluate = ft_convert_char_to_int(argc, args_to_evaluate, i);
	if (*size < 1)
		ft_free_and_call_ft_error(argc, args_to_evaluate, int_to_evaluate);
	if (argc == 2)
		ft_free_split(args_to_evaluate);
	return (int_to_evaluate);
}

// fonction pour generer ma liste avec des arguments valides

t_list	*ft_generate_list(int argc, char **argv)
{
	t_list	*list;
	int		*int_to_evaluate;
	int		i;
	int		size;

	int_to_evaluate = ft_handle_nb_of_args_and_convert_char_to_int(argc, argv,
			&size);
	if (!int_to_evaluate)
		return (NULL);
	list = ft_init_list();
	if (!list)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_fill_list(list, &int_to_evaluate[i]);
		i++;
	}
	ft_assign_index_to_list(list);
	free(int_to_evaluate);
	return (list);
}
