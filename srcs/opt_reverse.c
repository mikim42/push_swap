/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:00:30 by mikim             #+#    #+#             */
/*   Updated: 2017/07/31 17:43:49 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_r(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->a || !e->a->next || !e->b || !e->b->next)
		ps_ko(e);
	tmp = e->a;
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = e->a;
	e->a = new_head;
	tmp->next = NULL;
	tmp = e->b;
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = e->b;
	e->b = new_head;
	tmp->next = NULL;
	if (e->flag.visual)
		print_reverse(e, 3);
}

void	reverse_b(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->b || !e->b->next)
		ps_ko(e);
	tmp = e->b;
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = e->b;
	e->b = new_head;
	tmp->next = NULL;
	if (e->flag.visual)
		print_reverse(e, 2);
}

void	reverse_a(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *new_head;

	if (!e->a || !e->a->next)
		ps_ko(e);
	tmp = e->a;
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = e->a;
	e->a = new_head;
	tmp->next = NULL;
	if (e->flag.visual)
		print_reverse(e, 1);
}
