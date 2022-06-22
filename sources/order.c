/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:53:40 by msotelo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:14:52 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	order_size(t_struct *list)
{
	int	i;

	i = list->index_a;
	if (i == 2)
		algo_2_a(list);
	else if (i == 3)
		algo_3_a(list);
	else if (i == 4)
		algo_4(list);
	else if (i == 5)
		algo_5(list);
	else if (i > 5 && i <= 500)
		algo_small(list);
/*	else if (i > 100)
		algo_big(list);*/
	return;
}

void	algo_2_a(t_struct *list)
{
	if (list->a[0] > list->a[1])
		swap_a(list);
	return;
}

void	algo_3_a(t_struct *list)
{
	if (list->a[0] > list->a[1])
		swap_a(list);
	if (list->a[1] > list->a[2])
		reverse_rotate_a(list);
	if (list->a[0] > list->a[1])
		swap_a(list);
	return;
}

void	algo_2_b(t_struct *list)
{
	if (list->b[0] > list->b[1])
		swap_b(list);
	return;
}

void	algo_3_b(t_struct *list)
{
	if (list->b[0] > list->b[1])
		swap_b(list);
	if (list->b[1] > list->b[2])
		reverse_rotate_a(list);
	if (list->b[0] > list->b[1])
		swap_a(list);
	return;
}

void	algo_4(t_struct *list)
{
	while (list->a[0] != 0)
		reverse_rotate_a(list);
	push_b(list);
	algo_3_a(list);
	push_a(list);
	return ;
}

void	algo_5(t_struct *list)
{
	if (list->a[0] == 0 || list->a[1] == 0 || list->a[2] == 0)
		while (list->a[0] != 0)
			rotate_a(list);
	else
		while (list->a[0] != 0)
			reverse_rotate_a(list);
	push_b(list);
	if (list->a[0] == 1 || list->a[1] == 1 || list->a[2] == 1)
		while (list->a[0] != 1)
			rotate_a(list);
	else
		while (list->a[0] != 1)
			reverse_rotate_a(list);
	push_b(list);
	algo_3_a(list);
	push_a(list);
	push_a(list);
	return ;
}
