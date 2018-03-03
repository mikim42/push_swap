/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:00:30 by mikim             #+#    #+#             */
/*   Updated: 2017/07/31 17:43:55 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_r(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->a || !e->a->next || !e->b || !e->b->next)
		ps_ko(e);
	tmp = e->a;
	new_head = e->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = e->a;
	e->a->next = NULL;
	e->a = new_head;
	tmp = e->b;
	new_head = e->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = e->b;
	e->b->next = NULL;
	e->b = new_head;
	if (e->flag.visual)
		print_rotate(e, 3);
}

void	rotate_b(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->b || !e->b->next)
		ps_ko(e);
	tmp = e->b;
	new_head = e->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = e->b;
	e->b->next = NULL;
	e->b = new_head;
	if (e->flag.visual)
		print_rotate(e, 2);
}

void	rotate_a(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->a || !e->a->next)
		ps_ko(e);
	tmp = e->a;
	new_head = e->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = e->a;
	e->a->next = NULL;
	e->a = new_head;
	if (e->flag.visual)
		print_rotate(e, 1);
}
