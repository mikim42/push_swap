/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:48:15 by mikim             #+#    #+#             */
/*   Updated: 2017/08/05 00:51:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_rotate_b(t_psenv *e)
{
	t_stack *tmp;
	t_stack *last;
	int		cnt;

	if (!(tmp = e->b))
		return (0);
	cnt = -1;
	last = get_last(e->a);
	while (tmp)
	{
		cnt++;
		if (check_push_swap(e->a, tmp))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	return (cnt);
}

int		check_rotate_a(t_psenv *e)
{
	t_stack *tmp;
	int		cnt;

	if (!e->b)
		return (0);
	cnt = 0;
	tmp = e->a;
	while (tmp && tmp->next)
	{
		cnt++;
		if (PS_COMP(tmp->n, e->b->n, tmp->next->n) ||
			PS_COMP(e->b->n, tmp->next->n, tmp->n) ||
			PS_COMP(tmp->next->n, tmp->n, e->b->n))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	return (cnt);
}
