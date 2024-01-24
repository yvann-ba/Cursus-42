/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:23:33 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/24 09:43:47 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_nlist
{
	int				number;
	struct s_nlist	*next;
}					t_nlist;

int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_isprint(int c);
int		ft_isdigit(int d);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, unsigned long n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned long n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *str, int *error);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_free_char_tab(char **tab);
void	ft_free_int_tab(int **tab, int size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putnbr_fd(int n, int fd);

t_nlist	*ft_nlstnew(int number);
t_nlist	*ft_nlstnew(int number);
int		ft_nlstsize(t_nlist *lst);
t_nlist	*ft_nlstlast(t_nlist *lst);
void	ft_nlstiter(t_nlist *lst, void (*f)(int));
void	ft_nlstdelone(t_nlist *lst, void (*del)(int));
void	ft_nlstclear(t_nlist **lst);
void	ft_nlstadd_back(t_nlist **lst, t_nlist *new);
t_nlist	*ft_nlstmap(t_nlist *lst, int (*f)(int), void (*del)(int));
t_nlist	*ft_nlstmap_helper(t_nlist *lst, int (*f)(int),
			void (*del)(int), t_nlist **new_lst);

char	*ft_strndup(const char *s, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif