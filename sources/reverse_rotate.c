/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:40:08 by msotelo-          #+#    #+#             */
/*   Updated: 2022/06/25 20:02:33 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate_a(t_struct *list)
{
	int	aux;
	int	j;
	
	if (list->index_a < 2)
		return ;	
	j = list->index_a - 1;
	aux = list->a[j];
	if (!list->a)
		return ;
	write(1, "rra\n", 4);
	while (j >= 0)
	{
		list->a[j + 1] = list->a[j];
		j--;
	}
	list->a[0] = aux;
	return ;
}

void	reverse_rotate_b(t_struct *list)
{
	int	aux;
	int	j;
	
	if (list->index_b < 2)
		return ;
	j = list->index_b - 1;
	aux = list->b[j];
	if (!list->b)
		return ;
	write(1, "rrb\n", 4);
	while (j >= 0)
	{
		list->b[j + 1] = list->b[j];
		j--;
	}
	list->b[0] = aux;
	return ;
}

void	reverse_reverse(t_struct *list)
{
	write(1, "rrr\n", 4);
	reverse_rotate_a(list);
	reverse_rotate_b(list);
	return ;
}
