/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:01:59 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:06:31 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPE table->format.type
# define TCHAR table->data.c
# define TINT table->data.d
# define TUINT table->data.u
# define LENGTH table->format.length
# define TMP table->tmp
# define PRECISION table->format.precision
# define F_ZERO table->format.f_zero
# define F_HASH table->format.f_hash
# define F_MINUS table->format.f_minus
# define F_PLUS table->format.f_plus
# define F_SPACE table->format.f_space
# define FORM_SPEC table->format.str
# define WIDTH table->format.width
# define OUTPUT table->output
# define L_SHORT	1
# define L_SCHAR	2
# define L_LLONG	3
# define L_LONG		4
# define L_INTMAX	5
# define L_SIZET	6
# define MOD_U		0x100000000
# define MOD_SC		0x100
# define MOD_SH		0x10000

# include <libft.h>
# include <stdarg.h>

typedef struct			s_format
{
	int					is_good;
	int					f_minus;
	int					f_plus;
	int					f_space;
	int					f_zero;
	int					f_hash;
	int					width;
	int					precision;
	int					length;
	char				type;
	char				*str;
}						t_format;

typedef union			u_data
{
	char				*s;
	wchar_t				*ls;
	signed char			hhd;
	short				hd;
	long int			ld;
	long long			lld;
	intmax_t			jd;
	size_t				z;
	int					d;
	void				*p;
	unsigned char		hhu;
	unsigned short		hu;
	unsigned long		lu;
	unsigned long long	llu;
	uintmax_t			ju;
	unsigned int		u;
	char				c;
	wchar_t				lc;
}						t_data;

typedef struct			s_able
{
	t_format			format;
	t_data				data;
	char				*tmp;
	wchar_t				*wtmp;
	char				*output;
	wchar_t				*woutput;
	struct s_able		*next;
}						t_able;

char					**get_f_strs(char *format, int *size);
t_format				*get_format(char *str, int *num);
t_able					*generate_table(char *str, va_list a_list, int *num);

void					get_width(t_able *table, int *width, int *precision);

char					*ft_ctos(char c);
wchar_t					*ft_wctos(wchar_t c);
char					*ft_itoa(int n);
char					*ft_hhtoa(signed char n);
char					*ft_htoa(short n);
char					*ft_lltoa(long long n);
char					*ft_ltoa(long n);
char					*ft_jtoa(intmax_t n);
char					*ft_ztoa(size_t n);
char					*ft_utoa(unsigned int n, char base);
char					*ft_hhutoa(signed char n, char base);
char					*ft_hutoa(short n, char base);
char					*ft_llutoa(long long n, char base);
char					*ft_lutoa(long n, char base);
char					*ft_jutoa(intmax_t n, char base);
char					*ft_zutoa(size_t n, char base);

char					*replace(char *str, char *to_find, char *to_replace);
wchar_t					*ft_wstrdup(wchar_t *str);

void					parse_flags(t_format *t, char *format, int *start);
int						parse_length(t_format *t, char *format, int *start);
void					parse_width(t_format *t, char *format, int *start);
void					parse_precision(t_format *t, char *format, int *start);
int						parse_type(t_format *t, char *format, int *start);

t_format				parse_format(char *str);

void					set_data(t_able *table, va_list a_list);
void					set_char(t_able *table, va_list a_list);
void					set_str(t_able *table, va_list a_list);
void					set_uint(t_able *table, va_list a_list);
void					set_int(t_able *table, va_list a_list);
void					set_addr(t_able *table, va_list a_list);

void					set_tmp_char(t_able *table);
void					set_tmp_str(t_able *table);
void					set_tmp_uns(t_able *table);
void					set_tmp_int(t_able *table);
void					set_tmp(t_able *table);

void					set_output(t_able *table);

int						check_plus(t_able *table);
int						check_minus(t_able *table);
int						check_space(t_able *table);
void					handle_hash(t_able *table);
void					handle_zero(t_able *table);
void					handle_space(t_able *table);

char					*zero_str(int num);
int						is_sign(t_able *table);
int						is_neg(t_able *table);
int						is_good(t_able *table);
char					get_sign(t_able *table);
void					fix_sign(t_able *table);

int						ft_printf(const char *format, ...);

#endif
