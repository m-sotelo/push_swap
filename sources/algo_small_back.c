/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:57:18 by msotelo-          #+#    #+#             */
/*   Updated: 2022/07/12 20:13:58 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_this_way(t_struct *list, int i, int way)
{
	if (way == 0)
	{
		while (list->b[0] != i)
			rotate_b(list);
	}
	else
	{
		while (list->b[0] != i)
			reverse_rotate_b(list);
	}
}

// 0 = el numero esta arriba (rb), 1 = el numero esta abajo (rrb)

int	find_num(t_struct *list, int i)
{
	int	k;
	int	j;
	int	count;

	k = 0;
	j = list->index_b - 1;
	count = 0;
	while (list->b[k] != i)
	{
		count++;
		k++;
	}
	while (list->b[j] != i)
	{
		count--;
		j--;
	}
	if (count <= 0)
		return (0);
	else
		return (1);
}

void	algo_small_back(t_struct *list)
{
	int	i;
	int	j;
	int	k;
	int	way;

	j = 1;
	k = list->index_b;
	i = k - j;
	while (i != 0)
	{	
		way = find_num(list, i);
		rotate_this_way(list, i, way);
		push_a(list);
		j++;
		i = k - j;
	}
	push_a(list);
}
