/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:50:53 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/15 15:04:28 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void print_list(t_struct *list)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	printf("LISTA A:\n");
	while(i < list->index_a)
	{
		printf("Este es el elemento %i de la lista A:%i\n",i,list->a[i]);
		i++;
	}
	printf("LISTA B:\n");
	while(j < list->index_b)
	{
		printf("Este es el elemento %i de la lista B:%i\n",j,list->b[j]);
		j++;
	}
	return ;
}

