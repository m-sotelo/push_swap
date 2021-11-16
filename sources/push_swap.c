/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:24 by msotelo-          #+#    #+#             */
/*   Updated: 2021/11/16 16:44:06 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_strdup_struct(t_struct *list, t_struct *aux)
{
	int	i;

	i = 0;
	aux->a = (int *)malloc(sizeof(int) * list->index_a);
	while (i < list->index_a)
	{
		aux->a[i] = list->a[i];
		aux->index_a++;
		i++;
	}
	return ;
			if (list->a[i] < k[pos] && list->a[i] != k[pos - 1] && check == 1)
				k[pos] = list->a[i];
			
}

void	map_list(t_struct *list, int pos, int *k)
{
	int	i;
	int	j;
	t_struct aux;

	i = 0;
	j = 0;
	aux.a = NULL;
	ft_strdup_struct(list, &aux);
	k[pos] = list->a[pos];
	while (i < aux.index_a)
	{
		if (aux.a[i] < k[pos])
		{
			k[pos] = aux.a[i];
			j = i;
			printf("ESTO ES EN la PRIMERA VUELTA%i\n",aux.a[i]);
		}
		i++;
	}
	while (j < aux.index_a)
	{
		aux.a[j] = aux.a[j + 1];
		j++;
	}
	aux.index_a--;
	pos++;
	if(pos == (list->index_a - 1))
	{
		while(pos >= 0)
		{
			printf("ESTO ES K EN %i:%i\n", pos, k[pos]);
			pos--;
		}
		return ;
	}
	map_list(list, pos, k);
}

int		check_numbers(t_struct *list)
{
	int	i;
	int	j;

	i = list->index_a - 1;
	while (i >= 0)
	{
		j = list->index_a - 1;
		while (j >= 0)
		{
			if (list->a[i] == list->a[j] && i != j)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

void	free_list(t_struct *list)
{
	free(list->a);
	free(list->b);
	return ;
}

int	main(int argc, char **argv)
{
	int	check;
	int	check2;
	int	*k;
	t_struct list;

	list.a = malloc(sizeof(t_struct));
	list.b = malloc(sizeof(t_struct));
	list.index_a = 0;
	list.index_b = 0;
	check = fill_list(argc, argv, &list);
	check2 = check_numbers(&list);
	if (check == 0 || check2 == 0)
		write(1,"ERROR",5);
	print_list(&list);
	k = (int *)malloc(sizeof(int) * list.index_a);
	map_list(&list, 0, k);
	print_list(&list);
//	push_b(&list);
//	push_b(&list);
//	print_list(&list);
	free_list(&list);
	return (0);
}
