/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:56:19 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 20:02:13 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_inst(t_inst *head)
{
	if (head->next)
		destroy_inst(head->next);
	if (head->op)
		free(head->op);
	free(head);
}

void	destroy_stack(t_stack *head)
{
	if (head->next)
		destroy_stack(head->next);
	free(head);
}

void	destroy_psenv(t_psenv *e)
{
	int i;

	i = 0;
	if (e->a)
		destroy_stack(e->a);
	if (e->b)
		destroy_stack(e->b);
	if (e->inst)
		destroy_inst(e->inst);
}
