/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:58:33 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 22:56:31 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_op(t_psenv *e, char *inst)
{
	if (!ft_strcmp(inst, "pa"))
		push_a(e);
	else if (!ft_strcmp(inst, "pb"))
		push_b(e);
	else if (!ft_strcmp(inst, "sa"))
		swap_a(e);
	else if (!ft_strcmp(inst, "sb"))
		swap_b(e);
	else if (!ft_strcmp(inst, "ss"))
		swap_s(e);
	else if (!ft_strcmp(inst, "ra"))
		rotate_a(e);
	else if (!ft_strcmp(inst, "rb"))
		rotate_b(e);
	else if (!ft_strcmp(inst, "rr"))
		rotate_r(e);
	else if (!ft_strcmp(inst, "rra"))
		reverse_a(e);
	else if (!ft_strcmp(inst, "rrb"))
		reverse_b(e);
	else if (!ft_strcmp(inst, "rrr"))
		reverse_r(e);
	else
		ps_err(e);
}

void	run_chk_manual(t_psenv *e)
{
	char	*line;

	ft_printf("Enter an operation... \"finish\" to exit\n");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!ft_strcmp(line, "finish"))
			break ;
		check_op(e, line);
		ft_printf("Enter an operation... \"finish\" to exit\n");
		free(line);
	}
	free(line);
}

void	run_chk_next(t_psenv *e)
{
	t_inst	*tmp;
	char	*line;

	tmp = e->inst;
	ft_printf("Enter \"next(n)\"...\n");
	while (tmp)
	{
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (!ft_strcmp(line, "next") || !ft_strcmp(line, "n"))
				break ;
			ft_printf("Enter \"next(n)\"...\n");
			free(line);
		}
		free(line);
		check_op(e, tmp->op);
		tmp = tmp->next;
	}
}

void	run_chk_inst(t_psenv *e)
{
	t_inst	*tmp;
	int		i;

	i = 0;
	tmp = e->inst;
	while (tmp)
	{
		check_op(e, tmp->op);
		tmp = tmp->next;
		i++;
	}
	if (e->flag.res)
		e->flag.color ? print_last_color(e) : print_last(e);
	ft_printf("%d operations\n", i);
}
