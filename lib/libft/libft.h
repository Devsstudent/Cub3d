/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:38:41 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:46:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BASE_L "0123456789abcdef"
# define BASE_U "0123456789ABCDEF"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum e_bool{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_useful{
	t_bool	need_add;
	t_bool	need_neg;
	t_bool	prec;
}		t_useful;

typedef struct s_storage {
	void					*content;
	t_bool					space_after;
}							t_storage;

int		ft_printf(const char *string, ...);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s);
size_t	ft_len_till_nl(const char *s);
char	*get_next_line(int fd);
t_bool	ft_fill_buff(char *buff, int fd);
char	*ft_reset_buff(char *buff);
t_bool	ft_check_line(char *line);
char	*gnl_loop(char *line, char *buff, int fd);
void	printf_putchar(char c, int *ret_val);
int		ft_disp_space(char *str, int size, int index, int *ret_val);
void	ft_putnbr_addr(unsigned long nb, int *ret_val);
long	ft_power(long number, int power);
void	printf_putnbr(long nb, int *ret_val);
void	ft_putnbr_hexa(unsigned int nb, int *ret_val);
void	ft_putnbr_hexa_x(unsigned int nb, int *ret_val);
void	ft_apply_rules_before(char *str, int size, t_useful *sign, int *r_v);
void	ft_apply_minus_sign(char *str, int size, int *ret_val, t_useful *ned);
void	ft_precision(char *str, int size, t_useful *add_sign, int *ret_val);
int		ft_disp_zero(char *str, int size, int index, int *ret_val);
int		ft_calc_number_size(unsigned long value, char *str);
int		ft_calc_hexa_size(char *str, unsigned long value);
size_t	ft_strlen_special(char *s, char *pattern);
void	ft_manage_int(char *str, int value, int *ret_val, t_bool *not_end);
void	ft_manage_hexa(char *str, unsigned int val, int *r_v, t_bool *not_end);
void	ft_manage_string(char *str, char *value, int *ret_val, t_bool *not_end);
void	ft_manage_addr(char *str, void *addr, int *ret_val, t_bool *not_end);
void	ft_manage_char(char *str, char c, int *ret_val, t_bool *not_end);
void	ft_manage_unsigned(char *str, unsigned int val, int *r_v, t_bool *n_en);
t_bool	ft_check_addsign(char *str);
t_bool	ft_check_dieze(char *str);
t_bool	ft_is_digit(char c);
t_bool	ft_check_space(char *str);
void	ft_putnstr(char *str, int size, int *ret_val);
int		ft_printf(const char *string, ...);
void	ft_loop(char *string, va_list ap, int *ret_val);
char	*ft_brows(char *str, va_list ap, int *ret_val);
t_bool	ft_check_end(char c);
int		ft_need_sign(char *str, int size, t_useful *need_add, int *ret_val);
t_bool	ft_check_minus(char *str);
int		ft_check_precision(char *str, int expected_space, int size);
t_bool	ft_check_neg_sign(char *str);
t_bool	ft_check_novalue(char *str, unsigned int value);
t_bool	ft_check_precision_or_not(char *str);
void	ft_disp_space_neg(char *str, int size, int space, int *ret_val);
void	ft_init_struc(t_useful *init);
void	ft_manage_hexa_v1(int *i, t_useful *sign, t_bool *not_end, char *str);
int		ft_space(char *str, int *i, int *ret_val, int size);
t_bool	ft_space_at_start(char *str, int *i, t_useful *sign, int *ret_val);
t_bool	ft_check_zero_or_space(char *str);
void	ft_sharp(char x, int *r_v);

void	ft_bzero(void *s, size_t n);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);;
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdisplay(t_list **stack);
void	ft_sort_int_tab(int	*tab, int size);

#endif
