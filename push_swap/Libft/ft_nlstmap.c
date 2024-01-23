/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:36:07 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/23 11:47:52 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_nlist	*ft_nlstmap(t_nlist *lst, int (*f)(int), void (*del)(int))
{
	t_nlist	*new_lst;
	t_nlist	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_nlstnew(f(lst->number));
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_node = ft_nlstmap_helper(lst, f, del, &new_lst);
		if (!new_node)
			return (NULL);
		ft_nlstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

t_nlist	*ft_nlstmap_helper(t_nlist *lst, int (*f)(int),
	void (*del)(int), t_nlist **new_lst)
{
	t_nlist	*new_node;

	new_node = ft_nlstnew(f(lst->number));
	if (!new_node)
	{
		while (*new_lst)
		{
			new_node = (*new_lst)->next;
			del((*new_lst)->number);
			free(*new_lst);
			*new_lst = new_node;
		}
		return (NULL);
	}
	return (new_node);
}
