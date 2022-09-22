/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:07:23 by msotelo-          #+#    #+#             */
/*   Updated: 2022/09/23 00:53:49 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	last_pusheo(t_struct *list, int mid)
{
	while (list->index_a > 0)
	{
		push_b(list);
		check_pos(list, mid, list->b[0]);
	}
}

int	pos_calculator(t_struct *list, int i, int *aux)
{
	int	x;

	x = 0;
	while (aux[x] != -1)
	{
		if (list->a[i] == aux[x] && aux[x] >= 0)
			return (i);
		x++;
	}
	return (-1);
}

//0 = mitad inferior, 1 = mitad superior

int	first_push(t_struct *list, int mid, int *aux)
{
	int	i;
	int	k;

	i = -1;
	list->pos1 = -1;
	list->pos2 = -1;
	k = list->index_a;
	while (i++ <= mid)
	{
		list->pos1 = pos_calculator(list, i, aux);
		if (list->pos1 != -1)
			break ;
	}
	while (k > i)
	{
		list->pos2 = pos_calculator(list, k, aux);
		if (list->pos2 != -1)
			break ;
		k--;
	}
	list->pos2 = (list->index_a - list->pos2 - 1);
	if (list->pos2 < list->pos1)
		return (0);
	return (1);
}
