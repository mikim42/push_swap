/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 04:03:47 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:25 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_base(t_env *e, char type)
{
	long long			tmp;
	unsigned long long	val;

	val = 0;
	init_int_arg(e, &tmp);
	if (type == 'O')
		val = (unsigned long long)tmp;
	else if (e->mod == hh)
		val = (unsigned char)tmp;
	else if (e->mod == h)
		val = (unsigned short)tmp;
	else if (e->mod == none)
		val = (unsigned int)tmp;
	else if (e->mod == z || e->mod == t || e->mod == j || e->mod == l)
		val = (unsigned long)tmp;
	else if (e->mod == ll)
		val = (unsigned long long)tmp;
	(type == 'b' || type == 'B') ? e->out = ft_uns_lltoa_base(val, 2) : 0;
	(type == 'o' || type == 'O') ? e->out = ft_uns_lltoa_base(val, 8) : 0;
	(type == 'x' || type == 'X') ? e->out = ft_uns_lltoa_base(val, 16) : 0;
	if (type >= 'b' && type <= 'x')
		ft_lowcase(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	print_base(e, type, (long long)val);
}

void	spec_precision(t_env *e, char type)
{
	long double	ld;
	double		d;

	if (e->mod == L)
	{
		init_long_double(e, &ld);
		if (ld != ld || (ld * 2 == ld && ld != 0))
			return (nan_inf(e, type, ld));
	}
	else
	{
		init_prec_arg(e, &d);
		if (d != d || (d * 2 == d && d != 0))
			return (nan_inf(e, type, d));
		ld = (long double)d;
	}
	if (type == 'e' || type == 'E')
		return (print_prec_e(e, ld, type));
	if (type == 'f' || type == 'F')
		return (print_prec_f(e, ld));
	if (type == 'g' || type == 'G')
		return (print_prec_g(e, ld, type));
	if (type == 'a' || type == 'A')
		return (print_prec_a(e, ld, type));
}

void	spec_char(t_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (print_null_str(e));
		e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}

void	spec_unsint(t_env *e, char type)
{
	long long			tmp;

	e->flag.sp = 0;
	e->flag.plus = 0;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U')
		e->out = ft_uns_lltoa((unsigned long long)tmp);
	else if (e->mod == h)
		e->out = ft_uns_lltoa((unsigned short)tmp);
	else if (e->mod == hh)
		e->out = ft_uns_lltoa((unsigned char)tmp);
	else if (e->mod == none && type != 'U')
		e->out = ft_uns_lltoa((unsigned int)tmp);
	else if (e->mod == z || e->mod == l || e->mod == t || e->mod == j)
		e->out = ft_uns_lltoa((unsigned long)tmp);
	else if (e->mod == ll)
		e->out = ft_uns_lltoa((unsigned long long)tmp);
	print_digit(e);
}

void	spec_int(t_env *e)
{
	long long	tmp;
	long long	i;

	init_int_arg(e, &tmp);
	i = (long long)tmp;
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	e->flag.prec >= 0 ? e->flag.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->mod == hh)
		e->out = ft_itoa((char)i);
	else if (e->mod == h)
		e->out = ft_itoa((short)i);
	else if (e->mod == none)
		e->out = ft_itoa((int)i);
	else if (e->mod == l || e->mod == t)
		e->out = ft_ltoa((long)i);
	else if (e->mod == ll || e->mod == j)
		e->out = ft_lltoa((long long)i);
	print_digit(e);
}
