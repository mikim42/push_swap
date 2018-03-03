/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:38:51 by mikim             #+#    #+#             */
/*   Updated: 2018/03/03 15:20:44 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_dup(int *arr, int i, int gen)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (arr[j] == gen)
			return (0);
	}
	return (1);
}

void	num_gen(int *arr, int ran, int *i)
{
	int	n;
	int	gen;

	n = *i;
	srand(time(0) + n);
	while (n < ran)
	{
		gen = rand() % ran;
		if (check_dup(arr, n, gen))
			arr[n++] = gen;
	}
	*i = n;
}

int		*ran_gen(int ran)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_memalloc(sizeof(int) * ran);
	num_gen(arr, ran, &i);
	return (arr);
}

int		main(int ac, char **av)
{
	int ran;
	int	*arr;

	if (ac != 2)
		return (ft_printf("Error\n"));
	ran = ft_atoi(av[1]);
	if (ran < 0 || ran > 10000)
		return (ft_printf("min:0\nmax:10000\ntry again\n"));
	arr = ran_gen(ran);
	while (ran--)
		ft_printf("%d ", arr[ran]);
	ft_printf("\n");
	free(arr);
	return (0);
}
