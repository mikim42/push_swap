/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_psflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:54:51 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 23:06:50 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_instfile(t_psenv *e, char **av, int i)
{
	if (!ft_strcmp("./checker", av[0]))
	{
		if ((e->fd = open(av[1 + i], O_RDONLY)) < 0)
			ps_err(e);
	}
	else if (!ft_strcmp("./push_swap", av[0]))
	{
		if ((e->fd = open(av[1 + i], O_WRONLY | O_TRUNC | O_CREAT, 0744)) < 0)
			ps_err(e);
	}
	av[i + 1][0] = '\0';
}

int		check_psflag_visual(t_psenv *e, char c)
{
	if (c == 'v')
	{
		e->flag.res = 1;
		e->flag.visual = 1;
	}
	else if (c == 'g')
	{
		e->flag.res = 1;
		e->flag.visual = 1;
		e->flag.color = 1;
	}
	else if (c == 'c')
	{
		e->flag.next = 0;
		e->flag.manual = 0;
		e->flag.res = 1;
	}
	else if (c < '0' && c > '9')
		return (0);
	return (1);
}

int		check_psflag(t_psenv *e, char c)
{
	if (c == 'm')
	{
		e->flag.res = 0;
		e->flag.next = 0;
		e->flag.manual = 1;
	}
	else if (c == 'n')
	{
		e->flag.res = 0;
		e->flag.manual = 0;
		e->flag.visual = 1;
		e->flag.next = 1;
	}
	else
		return (check_psflag_visual(e, c));
	return (1);
}

void	init_psflag(t_psenv *e, char **av)
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (!ft_strcmp(av[i], "-help") || !ft_strcmp(av[i], "--help"))
			ps_help(!ft_strcmp(av[0], "./checker") ? 1 : 0);
		while (av[i][0] == '-' && av[i][++j])
		{
			if (av[i][j] == 'f')
			{
				e->flag.manual = 0;
				init_instfile(e, av, i);
			}
			else if (!check_psflag(e, av[i][j]) || av[0][1] == 'p')
			{
				ft_printf("\tillegal option -- {SET:BO}%c{OFF}\n", av[i][j]);
				ps_usage(!ft_strcmp(av[0], "./checker") ? 1 : 0);
			}
		}
	}
}
