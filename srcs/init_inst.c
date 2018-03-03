/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:29:24 by mikim             #+#    #+#             */
/*   Updated: 2017/07/31 16:20:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_inst(t_psenv *e, t_inst *n_inst)
{
	t_inst	*tmp;

	if (!(tmp = e->inst))
	{
		e->inst = n_inst;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n_inst;
	n_inst->prev = tmp->next;
}

t_inst	*create_inst(char *line)
{
	t_inst	*inst;

	inst = (t_inst*)malloc(sizeof(t_inst));
	inst->op = line;
	inst->prev = NULL;
	inst->next = NULL;
	return (inst);
}

void	init_inst(t_psenv *e)
{
	t_inst	*tmp;
	char	*line;

	while (get_next_line(e->fd, &line) > 0)
	{
		tmp = create_inst(line);
		add_inst(e, tmp);
	}
}
