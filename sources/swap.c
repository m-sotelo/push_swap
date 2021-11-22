/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:42:12 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/22 16:00:04 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_struct *list)
{
	int	aux;

	if (list->index_a <= 1)
		return ;
	write(1, "sa\n", 3);
	aux = list->a[0];
	list->a[0] = list->a[1];
	list->a[1] = aux;
	return ;
}

void	swap_b(t_struct *list)
{
	int	aux;

	if (list->index_b <= 1)
		return ;
	write(1, "sb\n", 3);
	aux = list->b[0];
	list->b[0] = list->b[1];
	list->b[1] = aux;
	return ;
}

void	swap_swap(t_struct *list)
{
	write(1, "ss\n", 3);
	swap_a(list);
	swap_b(list);
	return ;
}
