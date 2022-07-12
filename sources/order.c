/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:53:40 by msotelo-          #+#    #+#             */
/*   Updated: 2022/07/12 20:23:31 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algo_2_a(t_struct *list)
{
	if (list->a[0] > list->a[1])
		swap_a(list);
	return ;
}

void	algo_3_a(t_struct *list)
{
	if (list->a[0] > list->a[1])
		swap_a(list);
	if (list->a[1] > list->a[2])
		reverse_rotate_a(list);
	if (list->a[0] > list->a[1])
		swap_a(list);
	return ;
}

void	algo_2_b(t_struct *list)
{
	if (list->b[0] > list->b[1])
		swap_b(list);
	return ;
}

void	algo_3_b(t_struct *list)
{
	if (list->b[0] > list->b[1])
		swap_b(list);
	if (list->b[1] > list->b[2])
		reverse_rotate_a(list);
	if (list->b[0] > list->b[1])
		swap_a(list);
	return ;
}
