/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:30:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/28 14:34:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
/* Headers for LIBFT && GNL mandatory functions */
# include <stdarg.h>
/* Headers for ft_printf */

# include <stdbool.h>

# define DEC "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
/* Definitions for ft_printf */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif
/* Definitions for GNL BUFFER */

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define COLOR_RESET "\033[0m"
/* Color definitions for STDOUT */

typedef struct lib_s_list
{
	struct lib_s_list	*prev;
	void				*content;
	struct lib_s_list	*next;
}						t_list;
/* libft structures */

typedef struct s_list	t_char;
struct s_list
{
	char	c;
	t_char	*next;
};

typedef struct s_file_container
{
	int		index;
	int		read;
	int		len;
	int		fd;
	char	buffer[BUFFER_SIZE];
	t_char	*str;
}			t_file_container;
/* gnl structures */

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n_items, size_t size);
bool			ft_isalnum(int content);
bool			ft_isalpha(int c);
bool			ft_isascii(int content);
bool			ft_isdigit(int input);
bool			ft_isprint(int content);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t size);
char			*ft_strchr(const char *string, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t catsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t			ft_strlen(const char *content);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
char			*ft_strnstr(const char *haystack, const char *tofind, \
					size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/* libft Mandatory Part 1 Functions */

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long long int	ft_putnbr_fd(long long int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
/* libft Mandatory Part 2 Functions */

void			ft_lstadd_back_void(t_list **lst, t_list *new);
void			ft_lstadd_front_void(t_list **lst, t_list *new);
void			ft_lstclear_void(t_list **lst, void (*del)(void *));
void			ft_lstdelone_void(t_list *lst, void (*del)(void*));
t_list			*ft_lstend_void(t_list *list, void *value);
void			ft_lstiter_void(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast_t_list(t_list *lst);
t_list			*ft_lstmap_t_list(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
t_list			*ft_lstnew_t_list(void *content);
int				ft_lstsize_int(t_list *lst);
/* libft Bonus Functions - linked list */

int				ft_printf(const char *format, ...);
int				ft_printf_placeholder(char format, va_list ptr);
int				ft_putnbrbase(long long int n, char *base);
int				ft_putptr(long long int n, char *base);
int				ft_put_unsigned_nbr(unsigned long long int n, char *base);
/* ft_printf functions */

char			*ft_get_next_line(int fd);
char			*ft_gnl_get_line(t_file_container *file);
char			*ft_gnl_join_line(t_file_container *file);
/* gnl main prototype functions */

t_char			*ft_gnl_get_let(char let);
void			ft_gnl_join_let(t_char **head, t_char *new_let);
char			*ft_gnl_clear_nodes(t_char *str);
/* gnl prototype functions */

void			ft_error_msg(char *string);
char			*ft_dec_to_binary(int number);
char			*ft_strreversing_order(char *string);
/* my functions */

#endif
