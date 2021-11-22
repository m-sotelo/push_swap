/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:23:53 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/22 16:39:39 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_struct *list)
{
	int	j;
	int aux;

	j = 0;
	if (!list->a)
		return ;
	write (1, "ra\n", 3);
	aux = list->a[0];
	while (j < list->index_a)
	{
		list->a[j] = list->a[j + 1];
		j++;
	}
	list->a[j - 1] = aux;
	return ;
}

void	rotate_b(t_struct *list)
{
	int	j;
	int aux;

	j = 0;
	if (!list->b)
		return ;
	write (1, "rb\n", 3);
	aux = list->b[0];
	while (j < list->index_b)
	{
		list->b[j] = list->b[j + 1];
		j++;
	}
	list->b[j - 1] = aux;
	return ;
}

void	rotate_rotate(t_struct *list)
{
	write(1, "rr\n", 1);
	rotate_a(list);
	rotate_b(list);
	return ;
}

