/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:00:36 by pjang             #+#    #+#             */
/*   Updated: 2023/02/24 18:57:54 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define DECIMAL "0123456789"
# define HEXA_DECIMAL_UP "0123456789ABCDEF"
# define HEXA_DECIMAL_LOW "0123456789abcdef"
# define OPEN_MAX (10240)

// ft_printf

int			ft_printf(const char *format, ...);
void		get_conversion_index(const char *format, size_t *idx);
void		put_format(const char *format, size_t *result, \
				size_t *idx, va_list *ap);
int			is_conversion(char c);
void		put_nonflag(char c, va_list *ap, size_t *result);

// print

void		print_char(char c, size_t *result);
void		print_str(char *str, size_t *result);
void		print_nbr_base(long long nbr, char *base, size_t *result);
void		print_ptr(unsigned long ptr, size_t *result);

/* get_next_line.c */

char		*get_next_line(int fd);
void		division_str(char **str, int fd);
void		clear(int mode, char **str, char **buffer);
void		refresh(long long mode, char **str, char **buffer, char *temp);

/* get_next_line_utils.c */

long long	get_index(char *str);

// Part 1 - Libc functions

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

void		ft_bzero(void *s, size_t n);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(const char *str);

// using malloc

char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);

// Part 2 - Additional functions

char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
int			get_len(const char *s, char c);
char		*get_word(const char *s, char c);
int			get_strs(const char *s, char c);
char		**ft_split(const char *s, char c);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_itoa(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Bonus part

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
