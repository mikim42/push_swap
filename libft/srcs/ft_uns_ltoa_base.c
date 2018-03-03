/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_ltoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:37:29 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:10:34 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chklen(unsigned long n, int base, int *len)
{
	int i;

	i = 1;
	while (n >= (unsigned)base)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_uns_ltoa_base(unsigned long val, int base)
{
	char	*res;
	char	bs[17];
	int		len;

	len = 1;
	ft_strcpy(bs, "0123456789ABCDEF");
	ft_chklen(val, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	while (val >= (unsigned)base)
	{
		res[len--] = bs[val % base];
		val /= base;
	}
	res[len] = bs[val % base];
	return (res);
}
