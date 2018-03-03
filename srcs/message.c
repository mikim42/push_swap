/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:45:03 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 22:01:59 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_help(int p)
{
	if (p)
	{
		ft_printf("usage: ./checker [-cgmnv] [-f file] [arg ...]\n");
		ft_printf("\t{SET:BL}{SET:BO}{CYN}--help{OFF}\n");
		ft_printf("\t-c show last operation (off gmnv)\n");
		ft_printf("\t-f [file] read instruction from file (off m)\n");
		ft_printf("\t-g set color\n");
		ft_printf("\t-n operate instruction one by one\n");
		ft_printf("\t-m set manual\n");
		ft_printf("\t-v set visual\n");
	}
	else
	{
		ft_printf("usage: ./push_swap [-f file] [arg ...]\n");
		ft_printf("\t{SET:BL}{SET:BO}{CYN}--help{OFF}\n");
		ft_printf("\t-f [file] write instruction to file (off m)\n");
		ft_printf("\t   if file exist truncate, not create\n");
	}
	exit(EXIT_SUCCESS);
}

void	ps_usage(int p)
{
	if (p)
	{
		ft_printf("usage: ./checker [-cgmnv] [-f file] [arg ...]\n");
		ft_printf("        -help -- option details\n");
	}
	else
	{
		ft_printf("usage: ./push_swap [-f file] [arg ...]\n");
		ft_printf("        -help -- option details\n");
	}
	exit(EXIT_SUCCESS);
}

void	ps_err(t_psenv *e)
{
	destroy_psenv(e);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ps_ko(t_psenv *e)
{
	destroy_psenv(e);
	write(2, "KO\n", 3);
	exit(EXIT_SUCCESS);
}

void	ps_ok(t_psenv *e)
{
	destroy_psenv(e);
	write(2, "OK\n", 3);
	exit(EXIT_SUCCESS);
}
