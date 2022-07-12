/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:07:23 by msotelo-          #+#    #+#             */
/*   Updated: 2022/07/12 20:12:28 by msotelo-         ###   ########.fr       */
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

int	first_push_aux(t_struct *list, int i, int *aux, int sum)
{
	int	x;

	x = 0;
	while (aux[x] != -1)
	{
		if (list->a[i] == aux[x] && aux[x] >= 0)
			sum++;
		x++;
	}
	return (sum);
}

//0 = mitad inferior, 1 = mitad superior

int	first_push(t_struct *list, int mid, int *aux)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i <= mid)
	{
		sum = first_push_aux(list, i, aux, sum);
		i++;
	}
	while (i < list->index_a)
	{
		sum = first_push_aux(list, i, aux, sum);
		i++;
	}
	if (sum < 0)
		return (0);
	return (1);
}
