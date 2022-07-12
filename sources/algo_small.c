/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:59:09 by msotelo-          #+#    #+#             */
/*   Updated: 2022/07/12 20:11:59 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	calculate_chunk(t_struct *list)
{
	int	i;

	i = list->index_a;
	if (i > 5 && i < 50)
		return (5);
	if (i >= 50 && i < 150)
		return (10);
	if (i >= 150 && i < 250)
		return (15);
	if (i >= 250 && i < 350)
		return (20);
	return (25);
}

int	*create_ordered_list(t_struct *list, int chunk_size, int chunknum, int *aux)
{
	int	i;
	int	x;
	int	j;
	int	k;

	i = list->index_a;
	j = chunk_size * chunknum;
	x = -1;
	k = -1;
	if (aux == NULL)
		aux = malloc(sizeof(int) * ((chunk_size * 2) + 1));
	else
	{
		free(aux);
		aux = malloc(sizeof(int) * ((chunk_size * 2) + 1));
	}
	while (++x < i)
	{
		if (list->a[x] < (list->mid + j) && list->a[x] > (list->mid - j)
			&& (k < (chunk_size * 2)))
			aux[++k] = list->a[x];
	}
	aux[k] = -1;
	return (aux);
}

int	keep_going(t_struct *list, int chunk_size)
{
	if (list->index_a < chunk_size)
		return (1);
	return (0);
}

void	algo_small(t_struct *list)
{
	int	*nums;
	int	chunk_size;
	int	count;
	int	i;
	int	x;

	nums = NULL;
	x = 1;
	list->mid = (list->index_a / 2);
	chunk_size = calculate_chunk(list);
	count = list->index_a / chunk_size;
	while (keep_going(list, chunk_size) == 0)
	{
		nums = create_ordered_list(list, chunk_size, x, nums);
		i = first_push(list, list->mid, nums);
		pusheo(list, i, nums, list->mid);
		x++;
		count--;
	}
	last_pusheo(list, list->mid);
	algo_small_back(list);
}
