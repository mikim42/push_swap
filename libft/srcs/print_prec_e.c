/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:03:22 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:21 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_exponent(long double d, char type, char **expo)
{
	char	*tmp1;
	char	*tmp2;
	int		ex;

	d < 0 ? d *= -1 : 0;
	ex = 0;
	while (d >= 10)
	{
		d /= 10;
		ex++;
	}
	while (d < 1)
	{
		d *= 10;
		ex--;
	}
	if (ex > 9 || ex < -9)
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-" : "+");
	else
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-0" : "+0");
	tmp2 = ft_itoa(ex < 0 ? ex * -1 : ex);
	*expo = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

long	get_prec_num_e(long double d, int prec)
{
	int	neg;
	int	i;

	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (d < 1)
		d *= 10;
	while (d >= 10)
		d /= 10;
	i = -1;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}

void	ftoa_prec_e(t_env *e, long double d, char type)
{
	char	*tmp;
	char	*nb;
	char	*expo;
	long	num;
	int		prec;

	prec = (e->flag.prec >= 0 ? e->flag.prec : 6);
	num = (d == 0 ? 0 : get_prec_num_e(d, prec));
	nb = (d == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	d == 0 ? expo = ft_strjoin(&type, "+00") : get_exponent(d, type, &expo);
	tmp = (d < 0 ? ft_str_prec(nb, 2, prec + 1, e->flag.hash)
	: ft_str_prec(nb, 1, prec, e->flag.hash));
	e->out = ft_strjoin(tmp, expo);
	free(nb);
	free(tmp);
	free(expo);
}

void	print_prec_e(t_env *e, long double d, char type)
{
	ftoa_prec_e(e, d, type);
	if (e->flag.minus)
	{
		if (d > 0 && (e->flag.plus || e->flag.sp))
			e->ret += (e->flag.plus == 1 ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_prec_width(e);
	}
	else
	{
		print_prec_width(e);
		if (d > 0 && (e->flag.plus || e->flag.sp))
			e->ret += (e->flag.plus == 1 ? write(e->fd, "+", 1) :
			write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	e->i++;
	free(e->out);
}
