/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:56:49 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:42:51 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_push_swap(t_psenv *e)
{
	t_stack *last;

	if (PS_COMP(e->a->n, e->b->n, e->a->next->n) ||
		PS_COMP(e->b->n, e->a->next->n, e->a->n) ||
		PS_COMP(e->a->next->n, e->a->n, e->b->n))
	{
		store_push(e, ft_strdup("pa"));
		if (e->b && e->b->next && ft_abs(e->a->next->n - e->b->n) >
			ft_abs(e->a->next->n - e->b->next->n))
			return (store_swap(e, ft_strdup("ss")));
		else
			return (store_swap(e, ft_strdup("sa")));
	}
	last = get_last(e->a);
	if (PS_COMP(e->b->n, e->a->n, last->n) ||
		PS_COMP(e->a->n, last->n, e->b->n) ||
		PS_COMP(last->n, e->b->n, e->a->n))
		return (store_push(e, ft_strdup("pa")));
	if (e->b->next &&
		PS_COMP(e->b->next->n, e->a->n, last->n))
	{
		store_swap(e, ft_strdup("sb"));
		return (store_push(e, ft_strdup("pa")));
	}
}

int		check_push_swap(t_stack *a, t_stack *b)
{
	t_stack *last;

	last = get_last(a);
	if (!b || !a->next)
		return (0);
	if (PS_COMP(a->n, b->n, a->next->n))
		return (1);
	if (PS_COMP(b->n, a->n, last->n))
		return (1);
	if (PS_COMP(a->n, last->n, b->n))
		return (1);
	if (PS_COMP(last->n, b->n, a->n))
		return (1);
	if (b->next && PS_COMP(b->next->n, a->n, last->n))
		return (1);
	return (0);
}
