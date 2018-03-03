/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:25:21 by mikim             #+#    #+#             */
/*   Updated: 2017/07/31 21:34:40 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_list2
{
	void			*data;
	struct s_list2	*next;
}					t_list2;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

/*
** LIBFT
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_intlen(int n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *s, int base);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
int					ft_abs(int n);
int					ft_min(int a, int b);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_upcase(char *s);
void				ft_lowcase(char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char const *s1, char c, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long value, int base);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long value, int base);
char				*ft_uns_itoa(unsigned int n);
char				*ft_uns_ltoa(unsigned long n);
char				*ft_uns_lltoa(unsigned long long n);
char				*ft_uns_itoa_base(unsigned int n, int base);
char				*ft_uns_ltoa_base(unsigned long n, int base);
char				*ft_uns_lltoa_base(unsigned long long n, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** LIBFT_BONUS
*/

t_list2				*ft_create_elem(void *data);
void				ft_list_push_back(t_list2 **begin_list, void *data);
void				ft_list_push_front(t_list2 **beglin_list, void *data);
void				ft_list_clear(t_list2 **begin_list);
t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));

/*
** GET_NEXT_LINE
*/

# define BUFF_SIZE 32

int					ft_new_line(char **s, char **line, int fd, int ret);
int					get_next_line(const int fd, char **line);

/*
** FT_PRINTF
*/

/*
**				SETTINGS	EFFECT		COLORS
**				{OFF}		OFF SETTING	BLK		BLACK
**				{SET:BO}	BOLD		RED		RED
**				{SET:FT}	FAINT		GRN		GREEN
**				{SET:IT}	ITALIC		YEL		YELLOW
**				{SET:UL}	UNDERLINE	BLU		BLUE
**				{SET:RE}	REVERSE		MGT		MAGENTA
**				{SET:CC}	CONCEAL		CYN		CYAN
**				{SET:RV}	REVEAL		WHT		WHITE
**				{BGC:***}	BACKGROUND
**				{LT:***]	LIGHT COLO
*/

typedef enum		e_tag
{
	non = 0,
	pos
}					t_tag;

typedef struct		s_tags
{
	t_tag			tag;
	int				pos;
}					t_tags;

typedef struct		s_flag
{
	int				sp;
	int				plus;
	int				neg;
	int				minus;
	int				hash;
	int				zero;
	int				prec;
	int				width;
}					t_flag;

typedef enum		e_mod
{
	none = 0,
	h,
	hh,
	l,
	ll,
	j,
	z,
	t,
	L
}					t_mod;

typedef	struct		s_env
{
	va_list			ap[2];
	char			*out;
	t_tags			tags;
	t_flag			flag;
	t_mod			mod;
	int				fd;
	int				i;
	int				ret;
}					t_env;

/*
**					ft_printf
*/

int					ft_printf(const char *restrict fmt, ...);
void				init_env(t_env *e);
void				init_flag(t_flag *flag);
void				print_conversion(const char *restrict fmt, t_env *e);

/*
**					parse_arg
*/

void				get_tag(const char *restrict fmt, t_env *e);
void				get_flag(const char *restrict fmt, t_env *e);
void				get_prec(const char *restrict fmt, t_env *e);
void				get_width(t_env *e);
void				get_mod(const char *restrict fmt, t_env *e);
void				get_spec(const char *restrict fmt, t_env *e);
void				get_spec_more(const char *restrict fmt, t_env *e);

/*
**					init_args
*/

void				init_char_arg(t_env *e, int *tmp);
void				init_str_arg(t_env *e, char **tmp);
void				init_int_arg(t_env *e, long long *tmp);
void				init_prec_arg(t_env *e, double *tmp);
void				init_long_double(t_env *e, long double *tmp);
void				init_wchar_arg(t_env *e, wchar_t *tmp);
void				init_wstr_arg(t_env *e, wchar_t **tmp);

/*
**					get_spec
*/

void				spec_fd(t_env *e);
void				spec_int(t_env *e);
void				spec_unsint(t_env *e, char type);
void				spec_char(t_env *e, char type);
void				spec_wchar(t_env *e, char type);
void				spec_precision(t_env *e, char type);
void				spec_base(t_env *e, char type);
void				spec_return(t_env *e);
void				spec_ptraddr(t_env *e, char type);
void				spec_non_printable(t_env *e);
void				spec_percent(t_env *e);

/*
**					print_digit
*/

void				print_digit(t_env *e);
void				print_digit_width(t_env *e);
void				print_digit_sign(t_env *e);
void				check_digit_sign(t_env *e);
void				check_digit_prec(t_env *e);

/*
**					print_base
*/

void				print_base(t_env *e, char type, long long val);
void				print_base_width(t_env *e, char type);
void				print_base_pre(t_env *e, char type, long long val);
void				check_base_prec(t_env *e, char type);

/*
**					print_char
*/

void				print_char(t_env *e, char c);
void				print_null_char(t_env *e);
void				print_char_width(t_env *e);
void				print_str(t_env *e);
void				print_null_str(t_env *e);
void				print_str_width(t_env *e);

/*
**					print_wchar
*/

void				print_wchar(t_env *e, wchar_t wc);
void				print_wchar_minus(t_env *e, wchar_t wc);
void				print_wstr(t_env *e, wchar_t *wc);
void				print_wstr_minus(t_env *e, wchar_t *wc, int len);
int					get_wstr_len(wchar_t *wc);
void				put_wstr(t_env *e, wchar_t c);
void				put_wstr_c(t_env *e, char c);

/*
** 					print_prec_tools
*/

void				nan_inf(t_env *e, char type, double var);
void				nan_inf_long(t_env *e, char type, long double var);
void				print_prec_width(t_env *e);
char				*ft_ftoa(long double d);
char				*ft_str_prec(char *s1, int dot, int end, int hash);

/*
** 					print_prec_a
*/

void				print_prec_a(t_env *e, double d, char type);
void				print_prec_a_else(t_env *e, double d, char type);
void				ftoa_prec_a(t_env *e, double d, char type);
void				hex_prec(t_env *e, double d, char **frac, char type);
void				get_a_expo(double d, char type, char **expo);

/*
** 					print_prec_e
*/

void				print_prec_e(t_env *e, long double d, char type);
void				ftoa_prec_e(t_env *e, long double d, char type);
long				get_prec_num_e(long double d, int prec);
void				get_exponent(long double d, char type, char **expo);

/*
**					print_prec_f
*/

void				print_prec_f(t_env *e, long double d);
void				ftoa_prec_f(t_env *e, long double d);
long				get_prec_num_f(long double d, int prec);

/*
** 					print_prec_g
*/

void				print_prec_g(t_env *e, long double d, char type);
void				check_form(t_env *e, long double d, char type);
void				ftoa_prec_eg(t_env *e, long double d, char type, int prec);
void				ftoa_prec_fg(t_env *e, long double d, int end);
void				delete_zero(char *tmp);

/*
**					print_ptraddr
*/

void				print_ptraddr(t_env *e, char type);
void				print_ptraddr_width(t_env *e);
void				ptraddr_prec(t_env *e);

/*
**					print_invalid
*/

void				print_invalid_spec(t_env *e, char c);
void				print_invalid_width(t_env *e);

/*
**					print_non_printable
*/

void				print_non_printable(t_env *e);
void				print_zero_to_ten(t_env *e, char c);
void				print_ten_to_twenty(t_env *e, char c);
void				print_twenty_to_thirty(t_env *e, char c);

/*
**					print_dice
*/

void				print_dice(t_env *e);

/*
**					settings
*/

void				check_settings(const char *restrict fmt, t_env *e);
void				set_colo(const char *restrict fmt, t_env *e);
void				set_light_colo(const char *restrict fmt, t_env *e);
void				set_bg_colo(const char *restrict fmt, t_env *e);
void				set_options(const char *restrict fmt, t_env *e);

#endif
