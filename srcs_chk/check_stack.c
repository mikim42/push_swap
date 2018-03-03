/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:09:44 by mikim             #+#    #+#             */
/*   Updated: 2017/07/13 17:51:01 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_stack(t_psenv *e)
{
	t_stack	*tmp;

	if (e->b != NULL)
		ps_ko(e);
	tmp = e->a;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			ps_ko(e);
		tmp = tmp->next;
	}
	ps_ok(e);
}
