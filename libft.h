/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:22:20 by mfelida           #+#    #+#             */
/*   Updated: 2025/03/05 14:27:48 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
int			ft_atoi_base(const char *s, const char *base);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t new_size, size_t old_size);
void		*ft_memcpy(void *dest, void const *src, size_t n);
void		*ft_memmove(void *dest, void const *src, size_t n);
void		*ft_memchr(void *s, int c, size_t n);
int			ft_memcmp(void *s1, void *s2, size_t n);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_free(char **split);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putstr_fd(char *s, int fd);
ssize_t		ft_putendl_fd(char *s, int fd);
ssize_t		ft_putnbr_fd(int n, int fd);
ssize_t		ft_putuint_fd(unsigned int n, int fd);
ssize_t		ft_puthexu_fd(unsigned int n, int fd);
ssize_t		ft_puthexl_fd(unsigned int n, int fd);
ssize_t		ft_putpntr_fd(void *p, int fd);

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 42
# endif

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	cap;
}	t_string;

typedef struct s_ring_buffer
{
	char	data[GNL_BUFFER_SIZE];
	ssize_t	ridx;
	ssize_t	widx;
	char	full;
}	t_ring_buffer;

char		*ft_gnl(int fd);

int			ft_printf(const char *fmt, ...);
int			ft_fprintf(int fd, const char *fmt, ...);

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
