/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:54:12 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/16 16:25:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# define BUFF_SIZE 256
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

long long			ft_abs_ll(long long n);
int					ft_abs(int n);
double				ft_atof(const char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_countwordsspace(char const *str);
double				ft_f_abs(double n);
double				ft_fclamp(double n, double min, double max);
void				ft_freestrarr(char **arr);
char				*ft_ftoa(double n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isemptystr(char *str, int consider_space);
char				ft_isnumber(const char *str);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
char				*ft_lltoa(long long n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelcontent(void *content, size_t size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewfrom(void const *content, size_t content_size);
void				ft_lstreverse(t_list **alst);
void				ft_lstswap(t_list **before);
double				ft_max(double a, double b);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdeltabchar(char **str, int countwords);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
double				ft_min(double a, double b);
void				*ft_multi_free(int a, ...);
size_t				ft_numlen(int n);
size_t				ft_numulen(unsigned int n);
unsigned long long	ft_numullen(unsigned long long n);
char				*ft_pathjoin(char *p1, char *p2);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putnbrendl_fd(int n, int fd);
void				ft_putnbrendl(int n);
void				ft_putnstr(char *str, int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strendswith(char *s1, char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinch(char const *s1, char c);
char				*ft_strjoinchcl(char *s1, char c);
char				*ft_strjoincl(char *s1, char *s2, int free_both);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strreplace(char *str, char *term, char *replace_by);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplitspace(char const *s);
int					ft_strstartswith(char *s1, char *s2);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strtolower(char *s);
void				ft_strtoupper(char *s);
char				*ft_strtrim(char const *s);
void				ft_swap_double(double *a, double *b);
void				ft_swap(void *a, void *b);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					get_next_line(int const fd, char **line);
char				**ft_strsplit(char const *s, char c);

#endif
