/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_psenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:33:26 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 21:41:12 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*create_stack(int n)
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->n = n;
	stack->next = NULL;
	return (stack);
}

void	add_stack(t_psenv *e, int n)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		len;

	stack = create_stack(n);
	tmp = e->a;
	len = ft_intlen(n);
	len > e->len ? e->len = len : 0;
	if (!tmp)
		e->a = stack;
	else
		while (tmp)
		{
			if (tmp->n == stack->n)
			{
				free(stack);
				return (ps_err(e));
			}
			if (!tmp->next)
			{
				tmp->next = stack;
				return ;
			}
			tmp = tmp->next;
		}
}

int		check_av(t_psenv *e, char *av)
{
	long	tmp;
	int		i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if ((av[i] >= '0' && av[i] <= '9') || ((av[i] == '+' || av[i] == '-') &&
		(av[i + 1] >= '0' && av[i + 1] <= '9')))
		{
			tmp = ft_atoll(&av[i]);
			(tmp > INT_MAX || tmp < INT_MIN) ? ps_err(e) : 0;
			add_stack(e, (int)tmp);
			av[i] == '+' || av[i] == '-' ? i++ : 0;
			while (av[i] >= '0' && av[i] <= '9')
				i++;
		}
		else if (av[i] != '\0')
			return (0);
	}
	return (1);
}

int		init_psenv(t_psenv *e, char **av)
{
	int i;

	i = 1;
	e->len = 2;
	init_psflag(e, av);
	while (av[i] && av[i][0] == '-' && (av[i][1] < '0' || av[i][1] > '9'))
		i++;
	while (av[i])
	{
		if (!check_av(e, av[i++]))
			ps_err(e);
	}
	if (!e->a)
		ps_err(e);
	return (1);
}
