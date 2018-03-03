/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minimum_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:26:03 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:44:36 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_minimum_cross(t_psenv *e, int tmp[2])
{
	if (tmp[1] == 6)
	{
		while (e->crosa[0]-- > 0)
			store_rotate(e, ft_strdup("ra"));
		while (e->crosa[1]-- > 0)
			store_reverse(e, ft_strdup("rrb"));
	}
	else if (tmp[1] == 7)
	{
		while (e->crosb[0]-- > 0)
			store_rotate(e, ft_strdup("rb"));
		while (e->crosb[1]-- > 0)
			store_reverse(e, ft_strdup("rra"));
	}
}

void	get_minimum_rrrrr(t_psenv *e, int tmp[2])
{
	if (tmp[1] == 2)
	{
		while (e->rr[0]-- > 0)
			store_rotate(e, ft_strdup("rr"));
		while (e->rr[1]-- > 0)
			store_rotate(e, ft_strdup("ra"));
		while (e->rr[2]-- > 0)
			store_rotate(e, ft_strdup("rb"));
	}
	else if (tmp[1] == 5)
	{
		while (e->rrr[0]-- > 0)
			store_reverse(e, ft_strdup("rrr"));
		while (e->rrr[1]-- > 0)
			store_reverse(e, ft_strdup("rra"));
		while (e->rrr[2]-- > 0)
			store_reverse(e, ft_strdup("rrb"));
	}
}

void	get_minimum(t_psenv *e, int tmp[2])
{
	while (tmp[1] == 0 && tmp[0]-- > 0)
		store_rotate(e, ft_strdup("ra"));
	while (tmp[1] == 1 && tmp[0]-- > 0)
		store_rotate(e, ft_strdup("rb"));
	while (tmp[1] == 3 && tmp[0]-- > 0)
		store_reverse(e, ft_strdup("rra"));
	while (tmp[1] == 4 && tmp[0]-- > 0)
		store_reverse(e, ft_strdup("rrb"));
	if (tmp[1] == 2 || tmp[1] == 5)
		get_minimum_rrrrr(e, tmp);
	else if (tmp[1] == 6 || tmp[1] == 7)
		get_minimum_cross(e, tmp);
	get_push_swap(e);
}

void	get_op(t_psenv *e, int min[8])
{
	int	tmp[2];
	int	i;

	i = -1;
	tmp[0] = INT_MAX;
	while (++i < 8)
	{
		if (tmp[0] > min[i] && min[i] > 0)
		{
			tmp[0] = min[i];
			tmp[1] = i;
		}
	}
	get_minimum(e, tmp);
}
