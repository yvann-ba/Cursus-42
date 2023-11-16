/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:51 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/16 21:46:40 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(const char *format, va_list args)
{
	int	len;

	if (*format == 'c')
		len = ft_putlchar((char)va_arg(args, int));
	else if (*format == 's')
		len = ft_putlstr((char *)va_arg(args, char *));
	//else if (*format == 'p')
	//	continue ;
	else if (*format == 'd' || *format == 'i')
		len = ft_putlnbr_base((int)va_arg(args, int), "0123456789");
	else if (*format == 'u')
		len = ft_putlnbr_ubase((unsigned int)va_arg(args, unsigned int),
			"0123456789");
	else if (*format == 'x')
		len = ft_putlnbr_base((int)va_arg(args, int), "0123456789abcdef");
	else if (*format == 'X')
		len = ft_putlnbr_base((int)va_arg(args, int), "0123456789ABCDEF");
	else if (*format == '%')
	{
		write(1, "%%", 1);
		len = 1;
	}
	return (len);
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