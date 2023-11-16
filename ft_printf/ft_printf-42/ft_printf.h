/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:10:34 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/16 21:45:52 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putlnbr_base(int nbr, char *base);
int		ft_putlnbr_ubase(int nbr, char *base);
int		ft_putlchar(char c);
int		ft_putlstr(char *str);

#endif