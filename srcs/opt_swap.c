/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:00:30 by mikim             #+#    #+#             */
/*   Updated: 2017/07/31 17:44:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_s(t_psenv *e)
{
	t_stack	*tmp;

	if (!e->a || !e->a->next || !e->b || !e->b->next)
		ps_ko(e);
	tmp = e->a->next;
	e->a->next = tmp->next;
	tmp->next = e->a;
	e->a = tmp;
	tmp = e->b->next;
	e->b->next = tmp->next;
	tmp->next = e->b;
	e->b = tmp;
	if (e->flag.visual)
		print_swap(e, 3);
}

void	swap_b(t_psenv *e)
{
	t_stack	*tmp;

	if (!e->b || !e->b->next)
		ps_ko(e);
	tmp = e->b->next;
	e->b->next = tmp->next;
	tmp->next = e->b;
	e->b = tmp;
	if (e->flag.visual)
		print_swap(e, 2);
}

void	swap_a(t_psenv *e)
{
	t_stack	*tmp;

	if (!e->a || !e->a->next)
		ps_ko(e);
	tmp = e->a->next;
	e->a->next = tmp->next;
	tmp->next = e->a;
	e->a = tmp;
	if (e->flag.visual)
		print_swap(e, 1);
}
