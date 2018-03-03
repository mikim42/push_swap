/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:50:09 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:23 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_prec(char *s1, int dot, int end, int hash)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + 1);
	while (s1[++i] != '\0')
	{
		tmp[j++] = s1[i];
		if ((i == dot - 1 && end > 0) || hash == 1)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i >= end)
		{
			tmp[j] = '\0';
			break ;
		}
	}
	return (tmp);
}

char	*ft_ftoa(long double d)
{
	char	*s;
	long	tmp;
	int		len;
	int		neg;

	neg = (d < 0 ? -1 : 1);
	len = (d < 0 ? 1 : 0);
	d *= neg;
	tmp = (long)d;
	while (tmp > 0 && len++ >= 0)
		tmp /= 10;
	while (d - (long)d != 0 && len++ >= 0)
		d *= 10;
	s = ft_strnew(len);
	while (--len >= 0)
	{
		s[len] = (long)d % 10 + '0';
		d /= 10;
		if (neg == -1 && len == 1)
		{
			s[0] = '-';
			break ;
		}
	}
	return (s);
}

void	print_prec_width(t_env *e)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(e->out) + e->flag.plus + e->flag.sp;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			e->ret += e->flag.zero ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	nan_inf_long(t_env *e, char type, long double var)
{
	if (var != var)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "nan", 3);
		else
			e->ret += write(e->fd, "NAN", 3);
	}
	else if (var * 2 == var && var != 0)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "inf", 3);
		else
			e->ret += write(e->fd, "INF", 3);
	}
	e->i++;
}

void	nan_inf(t_env *e, char type, double var)
{
	if (var != var)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "nan", 3);
		else
			e->ret += write(e->fd, "NAN", 3);
	}
	else if (var * 2 == var && var != 0)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "inf", 3);
		else
			e->ret += write(e->fd, "INF", 3);
	}
	e->i++;
}
