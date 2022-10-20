/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:24 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/20 02:00:26 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_order(t_struct *list)
{
	int	i;

	i = 0;
	while (i < list->index_a)
	{
		if (list->a[i] > list->a[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_numbers(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_a - 1;
	while (i >= 0)
	{
		j = list->index_a - 1;
		while (j >= 0)
		{
			if (list->a[i] == list->a[j] && i != j)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

void	free_list(t_struct *list)
{
	free(list->a);
	free(list->b);
	return ;
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	int			check[2];
	int			x;
	int			i;
	t_struct	list;

	x = first_check(argc, argv);
	i = 0;
	init_list(&list, x);
	check[0] = fill_list(argc, argv, &list, i);
	check[1] = check_numbers(&list);
	if (check[0] == 0 || check[1] == 0)
	{
		write(1, "ERROR", 5);
		free_list(&list);
		exit(0);
	}
	write_null(&list);
	map_list(&list);
	list.order = check_order(&list);
	if (list.order == 0)
		return (0);
	order_size(&list);
	free_list(&list);
	return (0);
}
