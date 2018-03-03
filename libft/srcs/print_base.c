/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:47:27 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:14 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_base_pre(t_env *e, char type, long long val)
{
	if (e->flag.hash && e->out[0] != '\0' && val != 0)
	{
		e->ret += (type == 'o' || type == 'O') ? write(e->fd, "0", 1) : 0;
		e->ret += (type == 'x') ? write(e->fd, "0x", 2) : 0;
		e->ret += (type == 'X') ? write(e->fd, "0X", 2) : 0;
		type == 'a' || type == 'A' ? e->flag.width -= 2 : 0;
	}
	else if ((type == 'o' || type == 'O') && e->flag.hash && e->flag.prec >= 0)
		e->ret += write(e->fd, "0", 1);
	else if (type == 'a' || type == 'A')
	{
		if (e->flag.plus || e->flag.sp)
		{
			e->ret += e->flag.sp ? write(1, " ", 1) : write(1, "+", 1);
			e->flag.width--;
		}
		e->ret += type == 'a' ? write(e->fd, "0x", 2) : write(e->fd, "0X", 2);
		e->flag.width -= 2;
	}
}

void	print_base_width(t_env *e, char type)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(e->out);
	if (e->flag.hash && (e->out[0] != '\0' && e->out[0] != '0'))
	{
		e->flag.width -= ((type == 'o' || type == 'O') ? 1 : 0);
		e->flag.width -= ((type == 'x' || type == 'X') ? 2 : 0);
	}
	if (e->flag.prec >= 0)
	{
		while (e->flag.width > e->flag.prec + ++i && e->flag.width > len + i)
			e->ret += write(e->fd, " ", 1);
		while (e->flag.width > len + i++)
			e->ret += write(e->fd, "0", 1);
	}
	else
	{
		while (e->flag.width > len + ++i)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
	}
}

void	check_base_prec(t_env *e, char type)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		if ((type == 'o' || type == 'O') && e->flag.hash)
			e->flag.prec--;
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (--i >= 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}

void	print_base(t_env *e, char type, long long val)
{
	check_base_prec(e, type);
	if (e->flag.zero)
	{
		print_base_pre(e, type, val);
		print_base_width(e, type);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		print_base_pre(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_base_width(e, type);
	}
	else
	{
		print_base_width(e, type);
		print_base_pre(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	e->i++;
	free(e->out);
}
