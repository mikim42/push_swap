/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:01:35 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:42:31 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	store_reverse(t_psenv *e, char *op)
{
	if (!ft_strcmp("rra", op))
	{
		add_inst(e, create_inst(op));
		reverse_a(e);
	}
	else if (!ft_strcmp("rrb", op))
	{
		add_inst(e, create_inst(op));
		reverse_b(e);
	}
	else if (!ft_strcmp("rrr", op))
	{
		add_inst(e, create_inst(op));
		reverse_r(e);
	}
}

void	store_rotate(t_psenv *e, char *op)
{
	if (!ft_strcmp("ra", op))
	{
		add_inst(e, create_inst(op));
		rotate_a(e);
	}
	else if (!ft_strcmp("rb", op))
	{
		add_inst(e, create_inst(op));
		rotate_b(e);
	}
	else if (!ft_strcmp("rr", op))
	{
		add_inst(e, create_inst(op));
		rotate_r(e);
	}
}

void	store_swap(t_psenv *e, char *op)
{
	if (!ft_strcmp("sa", op))
	{
		add_inst(e, create_inst(op));
		swap_a(e);
	}
	else if (!ft_strcmp("sb", op))
	{
		add_inst(e, create_inst(op));
		swap_b(e);
	}
	else if (!ft_strcmp("ss", op))
	{
		add_inst(e, create_inst(op));
		swap_s(e);
	}
}

void	store_push(t_psenv *e, char *op)
{
	if (!ft_strcmp("pa", op))
	{
		add_inst(e, create_inst(op));
		push_a(e);
	}
	else if (!ft_strcmp("pb", op))
	{
		add_inst(e, create_inst(op));
		push_b(e);
	}
}

void	write_inst(t_psenv *e)
{
	t_inst	*tmp;

	tmp = e->inst;
	while (tmp)
	{
		ft_printf("%w%s\n", e->fd, tmp->op);
		tmp = tmp->next;
	}
}
