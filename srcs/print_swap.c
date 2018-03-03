/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:00:30 by mikim             #+#    #+#             */
/*   Updated: 2017/08/18 00:45:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_swap_color(t_psenv *e, t_stack *t1, t_stack *t2, int colo)
{
	if (colo == 1 || colo == 3)
		t1 == NULL ? ft_printf("{BGC:BLU} %*c{BGC:RED}", e->len + 1, 0) :
		ft_printf("{BGC:BLU}{SET:BL}{GRN} %*d{BGC:RED}", e->len, t1->n);
	else
		t1 == NULL ? ft_printf("{BGC:BLU} %*c{BGC:RED}", e->len + 1, 0) :
		ft_printf("{BGC:BLU} %*d{BGC:RED}", e->len, t1->n);
	if (colo == 2 || colo == 3)
		t2 == NULL ? ft_printf(" {BGC:BLU}%*c {OFF}\n", e->len + 1, 0) :
		ft_printf(" {BGC:BLU}{SET:BL}{GRN}%*d {OFF}\n", e->len, t2->n);
	else
		t2 == NULL ? ft_printf(" {BGC:BLU}%*c {OFF}\n", e->len + 1, 0) :
		ft_printf(" {OFF}{BGC:BLU}%*d {OFF}\n", e->len, t2->n);
}

void	print_swap_stack(t_psenv *e, int colo)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		curr;

	tmp1 = e->a;
	tmp2 = e->b;
	curr = 0;
	while (tmp1 || tmp2)
	{
		curr++;
		if (e->flag.color)
			print_swap_color(e, tmp1, tmp2, curr > 2 ? 0 : colo);
		else
		{
			tmp1 != NULL ? ft_printf("|%*d|", e->len, tmp1->n) :
			ft_printf("|%*|", e->len + 1);
			tmp2 != NULL ? ft_printf("%*d|\n", e->len, tmp2->n) :
			ft_printf("%*|\n", e->len + 1);
		}
		tmp1 ? tmp1 = tmp1->next : 0;
		tmp2 ? tmp2 = tmp2->next : 0;
	}
}

void	print_swap(t_psenv *e, int colo)
{
	colo == 1 ? ft_printf("{SET:BO}{LT:CYN}Exec SA:{OFF}\n") : 0;
	colo == 2 ? ft_printf("{SET:BO}{LT:CYN}Exec SB:{OFF}\n") : 0;
	colo == 3 ? ft_printf("{SET:BO}{LT:CYN}Exec SS:{OFF}\n") : 0;
	if (e->flag.color)
	{
		print_swap_stack(e, colo);
		colo != 2 ? ft_printf("{BGC:BLU}{SET:BO} %*c{OFF}", e->len, 'A') :
		ft_printf("{BGC:BLU} %*c{OFF}", e->len, 'A');
		colo != 1 ? ft_printf("{BGC:RED} {BGC:BLU}{SET:BO}%*c {OFF}\n\n",
		e->len, 'B') : ft_printf("{BGC:RED} {BGC:BLU}%*c {OFF}\n\n",
		e->len, 'B');
	}
	else
	{
		print_swap_stack(e, colo);
		ft_printf("|%*c|%*c|\n", e->len, 'A', e->len, 'B');
	}
}
