/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:27:17 by yvann             #+#    #+#             */
/*   Updated: 2023/11/12 12:19:36 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev_str_tab(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = 'a';

	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

static char	*ft_malloc_str(int n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		n = n * (-1);
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
	str = ft_rev_str_tab(str, ft_strlen(str));
	return (str);

}

#include <stdio.h>

int main()
{
	printf("%s", ft_itoa(123));
}
