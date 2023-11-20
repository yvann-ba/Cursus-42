/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:10:34 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/20 09:33:51 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_putlnbr_base(int nbr, char *base);
unsigned int	ft_putlnbr_ubase(unsigned int nbr, char *base);
int				ft_putlchar(char c);
int				ft_putlstr(char *str);

#endif