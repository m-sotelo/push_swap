/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:24 by msotelo-          #+#    #+#             */
/*   Updated: 2022/09/23 01:11:45 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	int			check;
	int			check2;
	int			x;
	int			i;
	t_struct	list;

	x = first_check(argc, argv);
	i = 0;
	init_list(&list, x);
	check = fill_list(argc, argv, &list, i);
	check2 = check_numbers(&list);
	if (check == 0 || check2 == 0)
	{
		write(1, "ERROR", 5);
		free_list(&list);
		exit(0);
	}
	write_null(&list);
//	print_list(&list);
	map_list(&list);
//	print_list(&list); // funcion de si esta ordenado no ordenar
	order_size(&list);
//	print_list(&list);
	free_list(&list);
//	atexit(leaks);
	return (0);
}
