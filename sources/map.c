/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:56 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/17 21:06:04 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	map_list(t_struct *list)
{
	int		i;
	int		j;
	long	aux;
	int		pos;
	int		*check;

	j = -1;
	check = (int *)malloc(sizeof(int) * list->index_a);
	while (++j < list->index_a)
	{
		i = -1;
		aux = 2147483648;
		while (++i < list->index_a)
		{
			if (list->a[i] <= aux && check[i] != 1)
			{
				pos = i;
				aux = list->a[i];
			}
		}
		list->a[pos] = j;
		check[pos] = 1;
	}
	free(check);
}
