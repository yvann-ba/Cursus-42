/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:33:49 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/23 11:50:20 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nlstdelone(t_nlist *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->number);
	free(lst);
}

