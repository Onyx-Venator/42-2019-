/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:25:12 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/05 16:31:43 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libftprintf/includes/libftprintf.h"
# include "../includes/color_shell.h"
# include <get_next_line.h>
# include <libft_lst.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long				ft_atoi_long(char const *s);
char				**ft_tabdup(char **t);
int					ft_free_tab(char ***t);
int					ft_tablen(char **t);
int					ft_max(int i, int j);
int					ft_min(int i, int j);
void				ft_print_int_tab(int *t, int size);
void				ft_int_tab_swap(int *t, int i, int j);
void				ft_quicksort(int *t, int start, int end);
char				*ft_strncpy(char *dst, const char *src, size_t len);

size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int cpwd);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
void				*ft_memset(void	*b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src,
	size_t n);
void				*ft_memccpy(void *dst, const void *src,
	int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strjoinfree(char *s1, char *s2, int tofree);
char				*ft_strnew(int i);
void				ft_strdel(char **str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char
	*needle, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strtrim_free(char const *s1, char const *set, int free);
int					ft_issep(char c, char sep);
int					ft_countstr(char *s, char sep);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstrchar_fd(char *s, char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

void				*ft_memalloc(int size);
char				*ft_realloc(char *str, int new_size, int old_size);
char				*ft_strndup(const char *s1, size_t maxlen);

#endif
