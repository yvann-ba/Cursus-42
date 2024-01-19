/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/19 13:27:52 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char *combine_args(int argc, char **argv)
{
	int i;
	char *str;
	char *tmp;

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

char **split_args(char *combined_args, char **tab)
{
	int i;
	tab = ft_split(combined_args, ' ');
	free(combined_args);
	while (tab[i])
		i++;
	return (i);
}
int *convert_tab_to_ints(char **tab)
{
	int i;
	int *nb_tab;

	i = 0;
	while (tab[i])
		i++;
	nb_tab = malloc(sizeof(int) * i);
	if (nb_tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		nb_tab[i] = ft_atoi(tab[i]);
		i++;
	}
	return (nb_tab);
}

int parsing(int argc, char **argv)
{
	int i;
	int *nb_tab;
	char *combined_args;
	char **tab;
	
	if (argc > 1)
	{
		combined_args = combine_args(argc, argv);
		i = split_args(combined_args, tab);
		nb_tab = convert_tab_to_ints(tab);
		ft_free_tab((void **)tab, i);
		if (nb_tab == NULL)
			return (return_error("malloc error"));
		i = 0;
		
	}
	else
		return (0);
		
}

int main(int argc, char **argv)  
{

	return (0);
}