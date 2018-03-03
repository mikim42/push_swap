/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 22:08:51 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 22:52:08 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_last_color(t_psenv *e)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = e->a;
	tmp2 = e->b;
	ft_printf("{SET:BO}{LT:CYN}Result:{OFF}\n");
	while (tmp1 || tmp2)
	{
		tmp1 != NULL ?
		ft_printf("{BGC:BLU}{WHT} %*d{BGC:RED} ", e->len, tmp1->n) :
		ft_printf("{BGC:BLU} %*c{BGC:RED} ", e->len + 1, 0);
		tmp2 != NULL ?
		ft_printf("{BGC:BLU}{SET:BO}{WHT}%*d {OFF}\n", e->len, tmp2->n) :
		ft_printf("{BGC:BLU}%*c {OFF}\n", e->len + 1, 0);
		tmp1 ? tmp1 = tmp1->next : 0;
		tmp2 ? tmp2 = tmp2->next : 0;
	}
	ft_printf("{BGC:BLU}{WHT} %*c{BGC:RED} ", e->len, 'A');
	ft_printf("{BGC:BLU}%*c {OFF}\n\n", e->len, 'B');
}

void	print_last(t_psenv *e)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = e->a;
	tmp2 = e->b;
	ft_printf("{SET:BO}{LT:CYN}Result:{OFF}\n");
	while (tmp1 || tmp2)
	{
		tmp1 != NULL ? ft_printf("|%*d|", e->len, tmp1->n) :
		ft_printf("|%*c|", e->len + 1, 0);
		tmp2 != NULL ? ft_printf("%*d|\n", e->len, tmp2->n) :
		ft_printf("%*c|\n", e->len + 1, 0);
		tmp1 ? tmp1 = tmp1->next : 0;
		tmp2 ? tmp2 = tmp2->next : 0;
	}
	ft_printf("|%*c|%*c|\n\n", e->len, 'A', e->len, 'B');
}

void	print_stack_color(t_psenv *e)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = e->a;
	tmp2 = e->b;
	ft_printf("{SET:BO}{LT:CYN}Init A and B:{OFF}\n");
	while (tmp1 || tmp2)
	{
		tmp1 != NULL ?
		ft_printf("{BGC:BLU}{WHT} %*d{BGC:RED} ", e->len, tmp1->n) :
		ft_printf("{BGC:BLU} %*c{BGC:RED} ", e->len + 1, 0);
		tmp2 != NULL ?
		ft_printf("{BGC:BLU}{SET:BO}{WHT}%*d {OFF}\n", e->len, tmp2->n) :
		ft_printf("{BGC:BLU}%*c {OFF}\n", e->len + 1, 0);
		tmp1 ? tmp1 = tmp1->next : 0;
		tmp2 ? tmp2 = tmp2->next : 0;
	}
	ft_printf("{BGC:BLU}{WHT} %*c{BGC:RED} ", e->len, 'A');
	ft_printf("{BGC:BLU}%*c {OFF}\n\n", e->len, 'B');
}

void	print_stack(t_psenv *e)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = e->a;
	tmp2 = e->b;
	ft_printf("{SET:BO}{LT:CYN}Init A and B:{OFF}\n");
	while (tmp1 || tmp2)
	{
		tmp1 != NULL ? ft_printf("|%*d|", e->len, tmp1->n) :
		ft_printf("|%*c|", e->len + 1, 0);
		tmp2 != NULL ? ft_printf("%*d|\n", e->len, tmp2->n) :
		ft_printf("%*c|\n", e->len + 1, 0);
		tmp1 ? tmp1 = tmp1->next : 0;
		tmp2 ? tmp2 = tmp2->next : 0;
	}
	ft_printf("|%*c|%*c|\n\n", e->len, 'A', e->len, 'B');
}
