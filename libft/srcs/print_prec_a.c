/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:57:18 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:20 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_a_expo(double d, char type, char **expo)
{
	char	*tmp;
	char	pre[3];
	int		i;

	i = 0;
	pre[2] = '\0';
	d < 0 ? d *= -1 : 0;
	pre[1] = ((d >= 1 || d == 0) ? '+' : '-');
	pre[0] = type + 15;
	while ((d >= 2 || d < 1) && d != 0)
	{
		if (d < 1)
			d *= 2;
		else
			d /= 2;
		i++;
	}
	tmp = ft_itoa(i);
	*expo = ft_strjoin(pre, tmp);
	free(tmp);
}

void	hex_prec(t_env *e, double d, char **frac, char type)
{
	unsigned long	cmp;
	long			num;
	int				len;
	int				cnt;
	int				i;

	len = (e->flag.prec < 0 ? 13 : e->flag.prec);
	*frac = ft_strnew(len);
	cmp = 0x0008000000000000;
	i = -1;
	num = *(long*)&d;
	while (++i < len)
	{
		cnt = 0;
		cnt += (num & cmp) == 0 ? 0 : 8;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 4;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 2;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 1;
		cmp >>= 1;
		frac[0][i] = (cnt < 10 ? cnt + 48 : cnt + type - 10);
	}
}

void	ftoa_prec_a(t_env *e, double d, char type)
{
	char	*frac;
	char	*ep;
	char	*tmp;

	d == 0 ? frac = ft_strdup("0") : hex_prec(e, d, &frac, type);
	d == 0 ? 0 : delete_zero(frac);
	get_a_expo(d, type, &ep);
	if (frac[0] == '\0')
		e->out = (d == 0 ? ft_strjoin("0", ep) : ft_strjoin("1", ep));
	else
	{
		tmp = (d == 0 ? ft_strdup(frac) : ft_strjoin("1.", frac));
		e->out = ft_strjoin(tmp, ep);
		free(tmp);
	}
	free(frac);
	free(ep);
	if (d < 0)
	{
		e->flag.plus = 0;
		e->flag.sp = 0;
		e->flag.width--;
	}
}

void	print_prec_a_else(t_env *e, double d, char type)
{
	e->flag.width -= 2;
	print_prec_width(e);
	d < 0 ? e->ret += write(1, "-", 1) : 0;
	print_base_pre(e, type, 1);
	e->ret += write(e->fd, e->out, ft_strlen(e->out));
}

void	print_prec_a(t_env *e, double d, char type)
{
	ftoa_prec_a(e, d, type);
	if (e->flag.zero)
	{
		d < 0 ? e->ret += write(1, "-", 1) : 0;
		print_base_pre(e, type, 1);
		print_prec_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		d < 0 ? e->ret += write(1, "-", 1) : 0;
		print_base_pre(e, type, 1);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_prec_width(e);
	}
	else
		print_prec_a_else(e, d, type);
	free(e->out);
	e->i++;
}
