/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:48:15 by mikim             #+#    #+#             */
/*   Updated: 2017/08/05 00:52:55 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_reverse_b(t_psenv *e)
{
	t_stack *tmp;
	t_stack	*last;
	int		cnt;
	int		point;

	if (!(tmp = e->b) || !e->b->next)
		return (0);
	cnt = 0;
	point = 0;
	last = get_last(e->a);
	while (tmp)
	{
		cnt++;
		if (check_push_swap(e->a, tmp))
			point = cnt;
		tmp = tmp->next;
	}
	if (point == 0)
		return (0);
	return (cnt - point + 1);
}

int		check_reverse_a(t_psenv *e)
{
	t_stack *tmp;
	int		cnt;
	int		point;

	if (!e->b)
		return (0);
	cnt = 0;
	point = 0;
	tmp = e->a;
	while (tmp->next)
	{
		cnt++;
		if (PS_COMP(tmp->n, e->b->n, tmp->next->n) ||
			PS_COMP(tmp->next->n, tmp->n, e->b->n))
			point = cnt;
		tmp = tmp->next;
	}
	if (point == 0)
		return (0);
	return (cnt - point + 1);
}
