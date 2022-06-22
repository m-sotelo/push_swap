/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:09:19 by msotelo-          #+#    #+#             */
/*   Updated: 2022/06/22 19:36:26 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	remalloc(t_struct *list)
{
	int	*aux_a;
	int	i;

	i = 0;
	aux_a = (int *)malloc(sizeof(int) * list->index_a);
	while (i < list->index_a)
	{
		aux_a[i] = list->a[i];
		i++;
	}
	free(list->a);
	free(list->b);
	list->a = malloc(sizeof(int) * list->index_a);
	list->b = malloc(sizeof(int) * list->index_a);
	i = 0;
	while (i < list->index_a)
	{
		list->a[i] = aux_a[i];
		i++;
	}
	list->max = list->index_a;
	free (aux_a);
}

