/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:25:08 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 22:21:33 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_psenv *e)
{
	if (check_sorted(e))
		return (write_inst(e));
	run_ps_auto(e);
	write_inst(e);
	destroy_psenv(e);
}

int		main(int ac, char **av)
{
	t_psenv e;

	ft_bzero(&e, sizeof(t_psenv));
	e.fd = 1;
	if (ac < 2)
		ps_usage(0);
	if (!init_psenv(&e, av))
		ps_err(&e);
	push_swap(&e);
	return (EXIT_SUCCESS);
}
