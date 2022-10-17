/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:57:18 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/17 18:18:32 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	rotate_this_way(t_struct *list, int i, int way)
{
	int	checker;

	checker = 0;
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
	return (0);
}

// 0 = el numero esta arriba (rb), 1 = el numero esta abajo (rrb)

int	find_num(t_struct *list, int i)
{
	int	k;
	int	mid;
	int	j;
	int	count;

	k = 0;
	mid = list->index_b / 2;
	j = i;
	count = 0;
	while (list->b[k] != i && k <= mid)
	{
		count++;
		k++;
	}
	if (list->b[k] == i)
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
	int	checker;

	j = 1;
	k = list->index_b;
	i = k - j;
	while (i != 0)
	{	
		way = find_num(list, i);
		checker = rotate_this_way(list, i, way);
		push_a(list);
		j++;
		i = k - j;
	}
	push_a(list);
}
