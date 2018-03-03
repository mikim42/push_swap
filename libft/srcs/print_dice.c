/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:00:17 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:14:15 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_dice(t_env *e)
{
	long long	ran;
	char		nb;
	double		d;
	int			i;

	init_int_arg(e, &ran);
	i = 0;
	d = (double)ran * 1.23456;
	while (i++ < 10)
	{
		d /= 12.34;
		d += ((long)d % 6 == 2 ? 1 : -1);
		d = (long)d;
		d += ((long)d % 6 == 4 ? 1 : -1);
		d *= 21.43;
		d += ((long)d % 6 == 0 ? 1 : -1);
	}
	nb = ((long)d % 6) + 49;
	e->ret += write(e->fd, &nb, 1);
	e->i++;
}
