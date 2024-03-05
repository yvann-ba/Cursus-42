/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:12:55 by ybarbot           #+#    #+#             */
/*   Updated: 2024/03/05 12:32:37 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token **tokens)
{
	t_token	*tmp;

	while (*tokens)
	{
		tmp = (*tokens)->next;
		free((*tokens)->value);
		free(*tokens);
		*tokens = tmp;
	}
}

int	main(void)
{
	const char	*input = "echo prout > file.txt | cat < file.txt >> file2.txt ; ls -l ; echo $?";
	t_token		*tokens;

	tokens = tokenize(input);
	ft_printf("Tokens:\n");
	while (tokens)
	{
		ft_printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
	free_tokens(&tokens);
	return (0);
}
