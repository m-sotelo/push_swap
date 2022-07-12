/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pusheo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:55:17 by msotelo-          #+#    #+#             */
/*   Updated: 2022/07/12 20:08:48 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_pos(t_struct *list, int mid, int num)
{
	if (num < mid && list->index_b > 1)
		rotate_b(list);
}

int	aux_len(int *aux)
{
	int	x;

	x = 0;
	while (aux[x] != -1)
		x++;
	x--;
	return (x);
}

void	pusheo_1(t_struct *list, int len, int *aux, int mid)
{
	int	x;

	while (len >= 0 && list->index_a > 2)
	{
		x = 0;
		while (aux[x] != -1)
		{
			if (list->a[0] == aux[x] && aux[x] >= 0)
			{
				push_b(list);
				check_pos(list, mid, list->b[0]);
				x = 0;
				len--;
			}
			x++;
		}
		reverse_rotate_a(list);
	}
}

void	pusheo_2(t_struct *list, int len, int *aux, int mid)
{
	int	x;

	while (len >= 0 && list->index_a > 2)
	{
		x = 0;
		while (aux[x] != -1)
		{
			if (list->a[0] == aux[x] && aux[x] >= 0)
			{
				push_b(list);
				check_pos(list, mid, list->b[0]);
				x = 0;
				len--;
			}
			x++;
		}
		rotate_a(list);
	}
}

void	pusheo(t_struct *list, int i, int *aux, int mid)
{
	int	len;

	len = aux_len(aux);
	if (i == 0)
		pusheo_1(list, len, aux, mid);
	else
		pusheo_2(list, len, aux, mid);
}
