/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:32:42 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/22 15:54:19 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_a - 1;
	j = 0;
	if(!list->b)
		return ;
	write(1, "pa\n", 3);
	while (i >= 0)
	{
		list->a[i + 1] = list->a[i];
		i--;
	}
	list->a[0] = list->b[0];
	list->index_b--;
	list->index_a++;
	while (j < list->index_b)
	{
		list->b[j] = list->b[j + 1];
	   	j++;	
	}
	list->b[j] = -1;
	return ;
}

void	push_b(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_b - 1;
	j = 0;
	if(!list->a)
		return ;
	write(1, "pb\n", 3);
	while (i >= 0)
	{
		list->b[i + 1] = list->b[i];
		i--;
	}
	list->b[0] = list->a[0];
	list->index_a--;
	list->index_b++;
	while (j < list->index_a)
	{
		list->a[j] = list->a[j + 1];
	   	j++;	
	}
	list->a[j] = -1;
	return ;
}

