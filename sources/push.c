/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:32:42 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/15 18:40:47 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_a;
	j = list->index_b;
	write(1, "pa\n", 3);
	if(!list->b)
		return ;
	while (i >= 0)
	{
		list->a[i + 1] = list->a[i];
		i--;		
	}
	list->a[0] = list->b[0];
	list->index_b--;
	list->index_a++;
	while (j >= 0)
	{
		list->b[j] = list->b[j + 1];
	   	j--;	
	}
	return ;
}

void	push_b(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_b - 1;
	j = list->index_a - 1;
	write(1, "pb\n", 3);
	if(!list->a)
		return ;
	while (i >= 0)
	{
		printf("ENTRO AQUI\n");
		list->b[i] = list->b[i + 1];
		i--;		
	}
	list->b[0] = list->a[0];
	list->index_a--;
	list->index_b++;
	while (j >= 0)
	{
		list->a[j + 1] = list->a[j];
	   	j--;
		printf("LISTA A EN %i DENTRO DEL WHILE:%i\n",j, list->a[j]);
	}
	return ;
}
