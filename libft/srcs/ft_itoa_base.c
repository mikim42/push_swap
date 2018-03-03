/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:55:03 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:07:41 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chklen(long n, int base, int *len)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n >= 1 || n <= -1)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_itoa_base(int val, int base)
{
	char	*res;
	char	bs[17];
	long	value;
	int		len;

	len = 1;
	value = (long)val;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (value == 0)
		return (ft_strdup("0"));
	ft_chklen(value, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	if (value < 0)
	{
		value *= -1;
		res[0] = '-';
	}
	while (value >= base)
	{
		res[len--] = bs[value % base];
		value /= base;
	}
	res[len] = bs[value % base];
	return (res);
}
