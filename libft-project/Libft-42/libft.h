/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:23:33 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/05 11:09:20 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_isprint(int c);
int		ft_isdigit(int d);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);


#endif