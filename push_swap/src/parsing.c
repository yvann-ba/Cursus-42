/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/24 10:14:14 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*combine_args(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (str);
}

int	split_args(char *combined_args, char ***tab)
{
	int	i;

	i = 0;
	*tab = ft_split(combined_args, ' ');
	if (*tab == NULL)
		return (ft_putendl_fd("Error tab null"));
	free(combined_args);
	while ((*tab)[i])
		i++;
	return (i);
}

int	*convert_tab_to_ints(char **tab, int *error)
{
	int	i;
	int	*nb_tab;
	int	conversion_error;

	i = 0;
	while (tab[i])
		i++;
	nb_tab = malloc(sizeof(int) * i);
	if (nb_tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		nb_tab[i] = ft_atoi(tab[i], &conversion_error);
		if (conversion_error)
		{
			free(nb_tab);
			*error = 1;
			return (NULL);
		}
		i++;
	}
	*error = 0;
	return (nb_tab);
}

int	parsing(int argc, char **argv, int **nb_tab)
{
	char	*combined_args;
	char	**tab;
	int		tab_len;
	int		error;

	if (argc > 1)
	{
		combined_args = combine_args(argc, argv);
		tab_len = split_args(combined_args, &tab);
		if (tab_len < 0 || !check_valid_duplicates(tab))
		{
			ft_free_char_tab(tab);
			return (ft_putendl_fd("Error"));
		}
		*nb_tab = convert_tab_to_ints(tab, &error);
		ft_free_char_tab(tab);
		if (error)
			return (ft_putendl_fd("Error"));
		if (is_sorted(*nb_tab, tab_len))
			return (0);
		return (tab_len);
	}
	else
		return (0);
}
