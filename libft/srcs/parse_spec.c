/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 03:25:42 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:16:28 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_fd(t_env *e)
{
	long long tmp;

	init_int_arg(e, &tmp);
	e->fd = (int)tmp;
	e->i++;
}

void	get_spec_more(const char *restrict fmt, t_env *e)
{
	if (fmt[e->i] == 'o' || fmt[e->i] == 'b' || fmt[e->i] == 'x' ||
			fmt[e->i] == 'O' || fmt[e->i] == 'B' || fmt[e->i] == 'X')
		spec_base(e, fmt[e->i]);
	else if (fmt[e->i] == 'n')
		spec_return(e);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		spec_ptraddr(e, fmt[e->i]);
	else if (fmt[e->i] == 'r')
		spec_non_printable(e);
	else if (fmt[e->i] == 'w')
		spec_fd(e);
	else if (fmt[e->i] == 'q')
		print_dice(e);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}

void	get_spec(const char *restrict fmt, t_env *e)
{
	if (fmt[e->i] == '%')
		spec_percent(e);
	else if ((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod != z)
		spec_int(e);
	else if (fmt[e->i] == 'u' || fmt[e->i] == 'U' || fmt[e->i] == 'D' ||
			((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod == z))
		spec_unsint(e, fmt[e->i]);
	else if ((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod != l)
		spec_char(e, fmt[e->i]);
	else if (fmt[e->i] == 'C' || fmt[e->i] == 'S')
		spec_char(e, fmt[e->i]);
	else if (((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod == l) ||
			fmt[e->i] == 'C' || fmt[e->i] == 'S')
		spec_wchar(e, fmt[e->i]);
	else if ((fmt[e->i] >= 'e' && fmt[e->i] <= 'g') || fmt[e->i] == 'a' ||
			(fmt[e->i] >= 'E' && fmt[e->i] <= 'G') || fmt[e->i] == 'A')
		spec_precision(e, fmt[e->i]);
	else
		get_spec_more(fmt, e);
}
