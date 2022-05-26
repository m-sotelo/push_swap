/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:59:09 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/26 16:43:26 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_side(t_struct *list, int i, int pivot)
{
	int	j;
	int	count;

	j = i - 1;
	count = 0;
	while (j >= pivot)
	{
		if (list->a[j] < (i / 2))
			count ++;
		j--;
	}
	j--;
	while (j >= 0)
	{
		if (list->a[j] < (i / 2))
 			count--;
		j--;
	}
	if (count <= 0)
		return (0);
	else
		return (1);
}

int	find_pivot(t_struct *list, int i)
{
	int	j;

	j = 0;
	while ((list->a[j] != (i / 2)))
		j++;
	return (j);
}

void	start_solve(t_struct *list, int check_size, int i)
{
	int	chunk_size;
	int	pivot;
	int side;
	int	j;
	int	check;
	int	check2;

	chunk_size = 5 * check_size;
	pivot = find_pivot(list, i);
	printf("esto es el pivot:%i\n", pivot);
	side = check_side(list, i, pivot);
	printf("essto es side:%i\n", side);
	j = i;
	i = 0;
	check = 0;
	check2 = 0;
	if (side == 0)
	{
		while (check == 0)
		{
			if (list->a[i] < (j / 2))
				push_b(list);
			else if (list->a[i] > (j / 2))
				rotate_a(list);
			else
			   check = 1;
		}
	}
	else
	{
		while (check == 0)
		{
			while (list->a[i] != (j / 2) && check2 == 0)
				rotate_a(list);
			if (check2 == 0)
				rotate_a(list);
			check2 = 1;
			if (list->a[i] < (j / 2))
				push_b(list);
			else if (list->a[i] > (j / 2))
			   rotate_a(list);
			else
				check = 1;
		}
	}
	return ;
}

void	algo_small(t_struct *list)
{
	int	i;
	int check_size;

	i = list->index_a;
	check_size = 0;
	if (i <= 25)
		check_size = 1;
	else if (i > 25 && i <= 50)
		check_size = 2;
	else if (i > 50 && i <= 75)
		check_size = 3;
	else if (i > 75 && i <= 100)
		check_size = 4;
	start_solve(list, check_size, i);
	return ;
}
