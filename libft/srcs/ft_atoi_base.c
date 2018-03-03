/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:55:20 by mikim             #+#    #+#             */
/*   Updated: 2017/04/20 23:31:56 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_putnum(const char *s, int base)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while ((s[i] >= '0' && s[i] <= '9') ||
			(s[i] >= 'a' && s[i] <= 'f') ||
			(s[i] >= 'A' && s[i] <= 'F'))
	{
		n *= base;
		if (s[i] >= '0' && s[i] <= '9')
			n += s[i] - 48;
		else if (s[i] >= 'a' && s[i] <= 'f')
			n += s[i] - 87;
		else if (s[i] >= 'A' && s[i] <= 'F')
			n += s[i] - 55;
		i++;
	}
	return (n);
}

int			ft_atoi_base(const char *s, int base)
{
	long	n;
	int		i;
	int		neg;

	n = 0;
	neg = 1;
	i = 0;
	while (s[i] == '\n' && s[i] == '\t' && s[i] == '\v' &&
			s[i] == ' ' && s[i] == '\f' && s[i] == '\r')
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	n = ft_putnum(s + i, base);
	return ((int)n * neg);
}
