/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:24 by msotelo-          #+#    #+#             */
/*   Updated: 2021/12/10 16:36:41 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_list(t_struct *list)
{
	list->a = malloc(sizeof(t_struct));
	list->b = malloc(sizeof(t_struct));
	list->index_a = 0;
	list->index_b = 0;
	return ;
}

int		check_numbers(t_struct *list)
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
	int			*k;
	t_struct 	list;
	t_struct	aux;

	init_list(&list);
	check = fill_list(argc, argv, &list);
	check2 = check_numbers(&list);
	if (check == 0 || check2 == 0)
		write(1,"ERROR",5);
	k = (int *)malloc(sizeof(int) * list.index_a);
	map_list(&list, 0, k, &aux);
	print_list(&list);
	order_size(&list);
	print_list(&list);
	free_list(&list);
	free(k);
//	atexit(leaks);
	return (0);
}
