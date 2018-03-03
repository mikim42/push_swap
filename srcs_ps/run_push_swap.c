/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:53:43 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:56:26 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_operation(t_psenv *e)
{
	int	min[8];

	if (check_push_swap(e->a, e->b))
		return (get_push_swap(e));
	ft_bzero(min, sizeof(min));
	min[0] = check_rotate_a(e);
	min[1] = check_rotate_b(e);
	min[2] = check_rotate_r(e);
	min[3] = check_reverse_a(e);
	min[4] = check_reverse_b(e);
	min[5] = check_reverse_r(e);
	min[6] = check_cross_a(e);
	min[7] = check_cross_b(e);
	get_op(e, min);
}

void	run_ps_auto(t_psenv *e)
{
	parse_stack(e);
	while (e->b)
		get_operation(e);
	if (!check_sorted(e))
		run_ps_auto(e);
}
