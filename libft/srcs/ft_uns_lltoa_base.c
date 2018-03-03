/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_lltoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:41:00 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:10:13 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chklen(unsigned long long n, int base, int *len)
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

char		*ft_uns_lltoa_base(unsigned long long val, int base)
{
	char	*res;
	char	bs[17];
	int		len;

	len = 1;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (val == 0)
		return (ft_strdup("0"));
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
