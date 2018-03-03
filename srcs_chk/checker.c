/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 20:58:58 by mikim             #+#    #+#             */
/*   Updated: 2017/07/15 16:47:01 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	checker(t_psenv *e)
{
	if (e->flag.visual)
		e->flag.color ? print_stack_color(e) : print_stack(e);
	if (e->flag.manual)
		run_chk_manual(e);
	else if (e->flag.next)
	{
		init_inst(e);
		run_chk_next(e);
	}
	else
	{
		init_inst(e);
		run_chk_inst(e);
	}
	check_stack(e);
}

int		main(int ac, char **av)
{
	t_psenv e;

	ft_bzero(&e, sizeof(t_psenv));
	if (ac < 2)
		ps_usage(1);
	if (!init_psenv(&e, av))
		ps_err(&e);
	checker(&e);
	return (EXIT_SUCCESS);
}
