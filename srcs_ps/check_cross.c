/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:08:11 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 20:00:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_crosb_num(t_psenv *e, int cnt[2], int max[2])
{
	int	crosb1;
	int	crosb2;

	crosb2 = max[0] - cnt[0] + 1;
	crosb1 = cnt[1] - 1;
	if (e->crosb[0] > 2000000000 || e->crosb[0] + e->crosb[1] > crosb1 + crosb2)
	{
		e->crosb[0] = crosb1;
		e->crosb[1] = crosb2;
	}
}

int		check_cross_b(t_psenv *e)
{
	t_stack	*tmp[2];
	int		cnt[2];
	int		max[2];

	ft_bzero(cnt, sizeof(cnt));
	ft_bzero(max, sizeof(max));
	ft_memset(e->crosb, 127, sizeof(e->crosb));
	get_stack_max(e, max);
	tmp[0] = e->a;
	while (tmp[0]->next && cnt[0]++ > -1)
	{
		tmp[1] = e->b;
		cnt[1] = 0;
		while (tmp[1] && cnt[1]++ > -1)
		{
			if (PS_COMP(tmp[0]->n, tmp[1]->n, tmp[0]->next->n) ||
				PS_COMP(tmp[1]->n, tmp[0]->next->n, tmp[0]->n) ||
				PS_COMP(tmp[0]->next->n, tmp[0]->n, tmp[1]->n))
				get_crosb_num(e, cnt, max);
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
	return (e->crosb[0] + e->crosb[1]);
}

void	get_crosa_num(t_psenv *e, int cnt[2], int max[2])
{
	int	crosa1;
	int	crosa2;

	crosa1 = cnt[0];
	crosa2 = max[1] - cnt[1] + 1;
	if (e->crosa[0] > 2000000000 || e->crosa[0] + e->crosa[1] > crosa1 + crosa2)
	{
		e->crosa[0] = crosa1;
		e->crosa[1] = crosa2;
	}
}

int		check_cross_a(t_psenv *e)
{
	t_stack	*tmp[2];
	int		cnt[2];
	int		max[2];

	ft_bzero(cnt, sizeof(cnt));
	ft_bzero(max, sizeof(max));
	ft_memset(e->crosa, 127, sizeof(e->crosa));
	get_stack_max(e, max);
	tmp[0] = e->a;
	while (tmp[0]->next && cnt[0]++ > -1)
	{
		tmp[1] = e->b;
		cnt[1] = 0;
		while (tmp[1] && cnt[1]++ > -1)
		{
			if (PS_COMP(tmp[0]->n, tmp[1]->n, tmp[0]->next->n) ||
				PS_COMP(tmp[1]->n, tmp[0]->next->n, tmp[0]->n) ||
				PS_COMP(tmp[0]->next->n, tmp[0]->n, tmp[1]->n))
				get_crosa_num(e, cnt, max);
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
	return (e->crosa[0] + e->crosa[1]);
}
