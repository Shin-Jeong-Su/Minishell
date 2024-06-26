/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:06:38 by seunghan          #+#    #+#             */
/*   Updated: 2024/05/29 12:47:30 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_env
{
	int	len;
	int	white_flag;
	int	d_quote;
}	t_env;

typedef struct s_list
{
	char			*token;
	int				token_idx;
	int				ctrl_token;
	int				quote_to_space;
	int				start;
	int				len;
	int				ambi_flag;
	int				tmp_flag;
	struct s_list	*next;
	struct s_list	*prev;
	t_env			*env_lset;
}	t_list;

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}	t_lst;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
size_t		ft_strlen(const char *s);
size_t		ft_strlen_js(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin_no_free(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
int			ft_putchar(char c);
size_t		ft_putstr_fd(char *s, int fd);
size_t		ft_putstr(char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_cnt(int n, int *num);
void		ft_putnbr_unsigned(unsigned int n, int *num);
void		ft_puthex_fd(long int n, int fd, int upper);
void		ft_puthex_cnt(unsigned long int n, int upper, int *num);
void		ft_putaddr_fd(void *addr, int fd);
void		ft_putaddr_cnt(void *addr, int *num);
//t_list
t_list		*ft_lstnew(t_list *now);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
//t_lst
t_lst		*lstnew(void *content);
void		lstadd_front(t_lst **lst, t_lst *new);
int			lstsize(t_lst *lst);
t_lst		*lstlast(t_lst *lst);
void		lstadd_back(t_lst **lst, t_lst *new);
void		lstdelone(t_lst *lst, void (*del)(void *));
char		*get_next_line(int fd);

#endif
