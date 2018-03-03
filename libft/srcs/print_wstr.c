/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:47:27 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:28 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_wstr_c(t_env *e, char c)
{
	e->ret += write(e->fd, &c, 1);
}

void	put_wstr(t_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wstr_c(e, c);
	else if (c <= 0x7FF)
	{
		put_wstr_c(e, (c >> 6) + 0xC0);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wstr_c(e, ((c >> 12) + 0xE0));
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wstr_c(e, (c >> 18) + 0xF0);
		put_wstr_c(e, ((c >> 12) & 0x3F) + 0x80);
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
}

int		get_wstr_len(wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}

void	print_wstr_minus(t_env *e, wchar_t *wc, int len)
{
	int i;

	i = -1;
	if (e->flag.prec >= 0)
	{
		while (wc[++i] != 0 && i < e->flag.prec)
			put_wstr(e, wc[i]);
	}
	else
	{
		while (wc[++i] != 0)
			put_wstr(e, wc[i]);
	}
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	print_wstr(t_env *e, wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = (e->flag.prec < 0 ? get_wstr_len(wc) : e->flag.prec);
	if (e->flag.minus)
		print_wstr_minus(e, wc, len);
	else
	{
		while (e->flag.width-- > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		if (e->flag.prec >= 0)
			while (wc[++i] != 0 && i * 4 < e->flag.prec)
				put_wstr(e, wc[i]);
		else
			while (wc[++i] != 0)
				put_wstr(e, wc[i]);
	}
	e->i++;
}
