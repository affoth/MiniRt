/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:09:08 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 16:50:11 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stddef.h>

# define FLT_MAX 3.402823466e+38F
# define MALLOC_FAIL "\033[0;31m Error\nMalloc failed!\n \033[0m"

typedef struct s_gc	t_gc;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

struct				s_gc
{
	void			*ptr;
	struct s_gc		*next;
};

double				ft_atof(const char *str);
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					contains_c(char *str, char c);
int					ft_isupper(char c);
int					ft_islower(char c);
double				ft_atof(const char *str);
char				*capitalize(char *str);
int					ft_count_words(char *s, char c);
char				*ft_chop(char *str, char c);

// list functions
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// get_next_line
char				*get_next_line(int fd);
char				*str_cutter(int *start, int *end, char **longstr,
						int free_me);
char				*ft_realloc(char **ptr, int size, int i);
int					specifier_check(const char *str, int i, int *plen,
						va_list *pargs);
int					ft_printf(const char *str, ...);

// ft_printf
void				ft_putchar_len(char c, int *plen);
void				ft_puthexanbr_len(unsigned long int nbr, char c, int *plen);
void				ft_putnbr_len(int n, int *plen);
void				ft_putstr_len(char *str, int *plen);
void				ft_putunsnbr_len(unsigned int n, int *plen);

//
void				ft_gc_init(t_gc *gc);
void				*gc_malloc(t_gc *gc, size_t size);
void				ft_gc_free(t_gc *gc);
char				*gc_substr(t_gc *gc, const char *s, unsigned int start,
						size_t len);
char				*gc_strtrim(t_gc *gc, char const *s1, char const *set);

char				*gc_strdup(t_gc *gc, const char *s);
char				*gc_chop(t_gc *gc, char *str, char c);

#endif
