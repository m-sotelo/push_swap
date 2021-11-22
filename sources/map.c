/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:56 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/22 18:40:13 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_strdup_struct(t_struct *list, t_struct *aux)
{
	int	i;

	i = 0;
	aux->a = (int *)malloc(sizeof(int) * list->index_a);
	while (i < list->index_a)
	{
		aux->a[i] = list->a[i];
		aux->index_a++;
		i++;
	}
	return ;
}

void	map_list_2(t_struct *list, int *k)
{
	int i;
	int j;

	i = 0;
	while (i < list->index_a)
	{
		j = 0;
		while (j < list->index_a)
		{
			if (list->a[i] == k[j])
				list->a[i] = j;
			j++;
		}
		i++;
	}
	return ;
}


void	map_list(t_struct *list, int pos, int *k, t_struct *aux)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pos == 0)
	{
		aux->a = NULL;
		aux->index_a = 0;
		ft_strdup_struct(list, aux);
	}
	k[pos] = aux->a[0];
	while (i < aux->index_a)
	{
		if (aux->a[i] < k[pos])
		{
			k[pos] = aux->a[i];
			j = i;
		}
		else if (aux->a[i] == k[pos])
			j = i;
		i++;
	}
	while (j < aux->index_a)
	{
		aux->a[j] = aux->a[j + 1];
		j++;
	}
	aux->index_a = aux->index_a - 1;
	if(pos == (list->index_a - 1))
	{
		free (aux->a);
		map_list_2(list, k);
		return ;
	}
	pos++;
	map_list(list, pos, k, aux);
}














