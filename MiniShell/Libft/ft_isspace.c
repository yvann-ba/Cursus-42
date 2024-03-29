/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:32:36 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/29 11:32:42 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
    return (c == ' ' || c == '\n' || c == '\t' ||
            c == '\v' || c == '\f' || c == '\r');
}
