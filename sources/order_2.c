/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordder_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:19:33 by msotelo-          #+#    #+#             */
/*   Updated: 2022/09/23 00:52:43 by msotelo-         ###   ########.fr       */
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
	else if (i > 5)
		algo_small(list);
	return ;
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
