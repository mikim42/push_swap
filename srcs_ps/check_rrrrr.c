/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rrrrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:08:11 by mikim             #+#    #+#             */
/*   Updated: 2017/08/18 01:23:31 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_stack_max(t_psenv *e, int max[2])
{
	t_stack *tmp;

	tmp = e->a;
	while (tmp)
	{
		max[0]++;
		tmp = tmp->next;
	}
	tmp = e->b;
	while (tmp)
	{
		max[1]++;
		tmp = tmp->next;
	}
}

void	get_rrr_num(t_psenv *e, int cnt[2], int max[2])
{
	int tmp[2];
	int	rrr1;
	int	rrr2;

	tmp[0] = max[0] - cnt[0];
	tmp[1] = max[1] - cnt[1] + 1;
	rrr1 = ft_min(tmp[0], tmp[1]);
	rrr2 = tmp[0] - tmp[1];
	if (rrr2 > 0 && e->rrr[0] + e->rrr[1] + e->rrr[2] > rrr1 + rrr2)
	{
		e->rrr[0] = rrr1;
		e->rrr[1] = rrr2;
		e->rrr[2] = 0;
	}
	else if (rrr2 < 0 &&
			e->rrr[0] + e->rrr[1] + e->rrr[2] > rrr1 + ft_abs(rrr2))
	{
		e->rrr[0] = rrr1;
		e->rrr[1] = 0;
		e->rrr[2] = ft_abs(rrr2);
	}
}

int		check_reverse_r(t_psenv *e)
{
	t_stack	*tmp[2];
	int		cnt[2];
	int		max[2];

	ft_bzero(cnt, sizeof(cnt));
	ft_bzero(max, sizeof(max));
	ft_memset(e->rrr, 127, sizeof(e->rrr));
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
				get_rrr_num(e, cnt, max);
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
	return (e->rrr[0] + e->rrr[1] + e->rrr[2]);
}

void	get_rr_num(t_psenv *e, int cnt[2])
{
	int	rr1;
	int	rr2;

	rr1 = ft_min(cnt[0], cnt[1]) - 1;
	rr2 = cnt[0] - cnt[1];
	if (rr2 > 0 && e->rr[0] + e->rr[1] + e->rr[2] > rr1 + rr2)
	{
		e->rr[0] = rr1;
		e->rr[1] = rr2;
		e->rr[2] = 0;
	}
	else if (rr2 < 0 && e->rr[0] + e->rr[1] + e->rr[2] > rr1 + ft_abs(rr2))
	{
		e->rr[0] = rr1;
		e->rr[1] = 0;
		e->rr[2] = ft_abs(rr2);
	}
}

int		check_rotate_r(t_psenv *e)
{
	t_stack	*tmp[2];
	int		cnt[2];

	ft_bzero(cnt, sizeof(cnt));
	ft_memset(e->rr, 127, sizeof(e->rr));
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
				get_rr_num(e, cnt);
			tmp[1] = tmp[1]->next;
		}
		tmp[0] = tmp[0]->next;
	}
	return (e->rr[0] + e->rr[1] + e->rr[2]);
}
