/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:51 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/16 16:55:09 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	check_format(const char *format, va_list args)
{
	if (*format == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (*format == 's')
		ft_putstr((char *)va_arg(args, char *));
	//else if (*format == 'p')
	//	continue ;
	else if (*format == 'd' || *format == 'i')
		ft_putlnbr_base((int)va_arg(args, int), "0123456789");
	else if (*format == 'u')
		ft_putlnbr_ubase((unsigned int)va_arg(args, unsigned int),
			"0123456789");
	else if (*format == 'x')
		ft_putlnbr_base((int)va_arg(args, int), "0123456789abcdef");
	else if (*format == 'X')
		ft_putlnbr_base((int)va_arg(args, int), "0123456789ABCDEF");
	else if (*format == '%')
		write(1, "%%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;	

	va_start (args, format);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			i = check_format(format, args);
		}
		format++;
	}
	return (i);
}

int main()
{
	int age = 18;
	char *str = "pipi";
	
	ft_printf("bonjour j'ai %d ans et %s", age, str);
}