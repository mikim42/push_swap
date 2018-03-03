/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:25:07 by mikim             #+#    #+#             */
/*   Updated: 2017/03/06 19:57:55 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list2 **begin_list)
{
	t_list2 *elem;
	t_list2 *tmp;

	elem = *begin_list;
	while (elem != NULL)
	{
		if (elem->next != NULL)
			tmp = elem->next;
		else
			tmp = NULL;
		free(elem);
		elem = tmp;
	}
	*begin_list = NULL;
}
