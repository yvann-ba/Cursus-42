/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:46:26 by ybarbot           #+#    #+#             */
/*   Updated: 2024/03/05 12:33:49 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"

typedef enum e_token_type
{
	TOKEN_WORD,          // 0
	TOKEN_REDIRECT_IN,   // 1 <
	TOKEN_REDIRECT_OUT,  // 2 >
	TOKEN_PIPE,          // 3 |
	TOKEN_DOUBLE_REDIRECT_OUT, // 4 >>
	TOKEN_HEREDOC,       // 5 <<
	TOKEN_SEMICOLON,     // 6 ;
	TOKEN_SINGLE_QUOTE,  // 7 '
	TOKEN_DOUBLE_QUOTE,  // 8 "
	TOKEN_ENV_VAR,       // 9 $
	TOKEN_EXIT_STATUS,   // 10 Status de sortie dernier programme exécuté : $?
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

t_token	*init_token(t_token_type type, char *value);
void	add_token(t_token **head, t_token *new_token);
int		is_special_char(char c);
void	identify_and_add_token(const char **input, t_token **head);
void	add_special_token(const char **input, t_token **head, \
		t_token_type type);
void	add_word_token(const char **input, t_token **head);
void	free_tokens(t_token **tokens);
t_token	*tokenize(const char *input);

#endif