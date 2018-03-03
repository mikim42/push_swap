/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 03:25:42 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:12 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_mod(const char *restrict fmt, t_env *e)
{
	if (fmt[e->i] == 'h' && fmt[e->i + 1] != 'h' && e->mod == none)
		e->mod = h;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] == 'h' && e->mod == none)
	{
		e->mod = hh;
		e->i++;
	}
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] != 'l')
		e->mod = l;
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] == 'l')
	{
		e->mod = ll;
		e->i++;
	}
	else if (fmt[e->i] == 'z')
		e->mod = z;
	else if (fmt[e->i] == 'j')
		e->mod = j;
	else if (fmt[e->i] == 'L')
		e->mod = L;
	else if (fmt[e->i] == 't')
		e->mod = t;
}

void	get_width(t_env *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width *= -1;
		e->flag.minus = 1;
	}
}

void	get_prec(const char *restrict fmt, t_env *e)
{
	if (e->flag.prec >= 0)
	{
		e->i++;
		return ;
	}
	if (fmt[e->i] == '.' && fmt[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (fmt[e->i] == '.')
	{
		e->i++;
		e->flag.prec = ft_atoi(fmt + e->i);
		while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
			e->i++;
	}
}

void	get_flag(const char *restrict fmt, t_env *e)
{
	while (fmt[e->i] == 32 || fmt[e->i] == 35 || fmt[e->i] == 46 ||
	(fmt[e->i] > 47 && fmt[e->i] < 58) || fmt[e->i] == 42 || fmt[e->i] == 43 ||
	fmt[e->i] == 45 || fmt[e->i] == 'z' || fmt[e->i] == 'h' || fmt[e->i] == 'j'
	|| fmt[e->i] == 'l' || fmt[e->i] == 't' || fmt[e->i] == 'L')
	{
		fmt[e->i] >= 'L' && fmt[e->i] <= 'z' ? get_mod(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sp = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '*' ? get_width(e) : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			get_prec(fmt, e);
		else if (fmt[e->i] >= '1' && fmt[e->i] <= '9' && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(fmt + e->i);
			while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
				e->i++;
		}
		else
			e->i++;
	}
}

void	get_tag(const char *restrict fmt, t_env *e)
{
	int	i;
	int tmp;

	init_flag(&e->flag);
	e->mod = none;
	e->tags.tag = non;
	i = 0;
	if (fmt[e->i] >= '0' && fmt[e->i] <= '9')
	{
		tmp = ft_atoi(fmt + e->i);
		while (fmt[e->i + i] >= '0' && fmt[e->i + i] <= '9')
			i++;
		if (fmt[e->i + i] == '$')
		{
			e->tags.tag = pos;
			e->tags.pos = tmp;
			e->i += i + 1;
		}
	}
}
