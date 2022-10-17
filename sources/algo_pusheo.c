/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pusheo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:55:17 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/17 18:18:49 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_pos(t_struct *list, int mid, int num)
{
	if (num < mid && list->index_b > 1)
	{
		rotate_b(list);
		return (1);
	}
	return (0);
}

int	aux_len(int *aux)
{
	int	x;

	x = 0;
	while (aux[x] != -1)
		x++;
	return (x);
}

void	pusheo_1(t_struct *list, int mid)
{
	int	x;

	x = list->a[list->pos2];
	while (list->a[0] != x)
		reverse_rotate_a(list);
	push_b(list);
	check_pos(list, mid, list->b[0]);
}

void	pusheo_2(t_struct *list, int mid)
{
	int	x;

	x = list->a[list->pos1];
	while (list->a[0] != x)
		rotate_a(list);
	push_b(list);
	check_pos(list, mid, list->b[0]);
}

void	pusheo(t_struct *list, int i, int mid)
{
	if (i == 0)
		pusheo_1(list, mid);
	else
		pusheo_2(list, mid);
}
