/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:41:00 by mikim             #+#    #+#             */
/*   Updated: 2017/04/30 09:08:06 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chklen(long long n, int base, int *len)
{
	int i;

	i = 0;
	n < 0 ? n *= -1 : 0;
	if (n < 0)
		i++;
	while (n >= 1 || n <= -1)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_lltoa_base(long long val, int base)
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
	val < 0 ? res[0] = '-' : 0;
	val < 0 ? val *= -1 : 0;
	while (val >= base)
	{
		res[len--] = bs[val % base];
		val /= base;
	}
	res[len] = bs[val % base];
	return (res);
}
