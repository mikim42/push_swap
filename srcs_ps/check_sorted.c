/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:56:25 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:43:55 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*get_last(t_stack *head)
{
	t_stack	*last;

	last = head;
	while (last->next)
		last = last->next;
	return (last);
}

void	sort_rot(t_psenv *e, int cnt[2])
{
	int	r;

	if (cnt[1] > (cnt[0] / 2) + 1)
	{
		r = cnt[0] - cnt[1] + 1;
		while (r-- > 0)
			store_reverse(e, ft_strdup("rra"));
	}
	else
	{
		r = cnt[1] - 1;
		while (r-- > 0)
			store_rotate(e, ft_strdup("ra"));
	}
}

void	check_sort_rot(t_psenv *e)
{
	t_stack *tmp;
	int		min;
	int		cnt[2];

	min = INT_MAX;
	ft_bzero(cnt, sizeof(cnt));
	tmp = e->a;
	while (tmp)
	{
		cnt[0]++;
		if (min > tmp->n)
		{
			min = tmp->n;
			cnt[1] = cnt[0];
		}
		tmp = tmp->next;
	}
	sort_rot(e, cnt);
}

int		check_sorted(t_psenv *e)
{
	t_stack	*tmp;
	t_stack *last;
	int		flag;

	if (e->b)
		return (0);
	tmp = e->a;
	last = get_last(e->a);
	flag = 0;
	while (tmp)
	{
		if (tmp->next && tmp->n > tmp->next->n)
			flag++;
		if (flag == 2)
			return (0);
		tmp = tmp->next;
	}
	check_sort_rot(e);
	return (1);
}
