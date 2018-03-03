/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:16:09 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:10:02 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chklen(unsigned long n, int base, int *len)
{
	int i;

	i = 0;
	while (n >= (unsigned)base)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_uns_itoa_base(unsigned int val, int base)
{
	char			*res;
	char			bs[17];
	unsigned long	value;
	int				len;

	len = 1;
	value = (unsigned long)val;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (value == 0)
		return (ft_strdup("0"));
	ft_chklen(value, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	while (value >= (unsigned)base)
	{
		res[len--] = bs[value % base];
		value /= base;
	}
	res[len] = bs[value % base];
	return (res);
}
