/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:27:17 by yvann             #+#    #+#             */
/*   Updated: 2023/11/12 13:53:03 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev_str_tab(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = 'a';
	if (str[0] == '-')
	{
		i++;
	}
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str);
}

static char	*ft_malloc_str(int n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (n == 0)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	str = ft_malloc_str(n);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	if (str[0] == '-')
		str = ft_rev_str_tab(str + 1, i - 1);
	else
		str = ft_rev_str_tab(str, i);
	return (str);

}

#include <stdio.h>

int main()
{
	printf("%s", ft_itoa(123));
}
