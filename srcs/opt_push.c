/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:14:19 by mikim             #+#    #+#             */
/*   Updated: 2017/07/15 20:20:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_b(t_psenv *e)
{
	t_stack	*tmp;

	if (e->a == NULL)
		ps_ko(e);
	tmp = e->a->next;
	e->a->next = e->b;
	e->b = e->a;
	e->a = tmp;
	if (e->flag.visual)
		print_push(e, 2);
}

void	push_a(t_psenv *e)
{
	t_stack	*tmp;

	if (e->b == NULL)
		ps_ko(e);
	tmp = e->b->next;
	e->b->next = e->a;
	e->a = e->b;
	e->b = tmp;
	if (e->flag.visual)
		print_push(e, 1);
}
