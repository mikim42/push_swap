/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:22:24 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:35:08 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		parse_check(t_psenv *e)
{
	t_stack *tmp;
	int		prev;

	if (!e->a->next->next)
		return (1);
	prev = e->a->n;
	tmp = e->a->next;
	while (tmp)
	{
		if (prev > tmp->n)
			return (0);
		prev = tmp->n;
		tmp = tmp->next;
	}
	return (1);
}

void	parse_stack(t_psenv *e)
{
	int	last;

	e->last = get_last(e->a)->n;
	while (e->last != e->a->n && e->a->next->next)
	{
		last = get_last(e->a)->n;
		if (PS_COMP(last, e->a->n, e->a->next->n) ||
			PS_COMP(e->a->next->n, last, e->a->n))
			store_rotate(e, ft_strdup("ra"));
		else if (PS_COMP(last, e->a->next->n, e->a->n))
		{
			if (e->b && e->b->next && e->b->next->n > e->b->n)
				store_swap(e, ft_strdup("ss"));
			else
				store_swap(e, ft_strdup("sa"));
			store_rotate(e, ft_strdup("ra"));
		}
		else
			store_push(e, ft_strdup("pb"));
		if (parse_check(e))
			break ;
	}
}
