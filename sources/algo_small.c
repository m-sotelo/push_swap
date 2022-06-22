/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:59:09 by msotelo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:14:56 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_pos(t_struct *list, int mid, int num)
{
	if (num < mid && list->index_b > 1)
	{
//		printf("esto es el mid:%i y esto lo que estoy pasando:%i\n", mid, num);
		rotate_b(list);
	}
}

int		aux_len(int *aux)
{
	int	x;

	x = 0;
	while(aux[x])
		x++;
	return (x);
}

void	pusheo(t_struct *list, int i, int *aux, int mid)
{
	int	x;
	int	len;

	len = aux_len(aux);
	if (i == 0)
	{
		while (1)
		{
			x = 0;
			while (aux[x])
			{
//				printf("esto es aux en %i: %i y esto es la lista:%i y esto len:%i\n",x, aux[x], list->a[0], len);
//				usleep(100000);
				if (list->a[0] == aux[x])
				{
					push_b(list);
					check_pos(list, mid , list->b[0]);
					x = 0;
					len--;
				}
				x++;
			}
			if (len == 0)
				break ;
			reverse_rotate_a(list);
		}
	}
	else
	{
		while (1)
		{
			x = 0;
			while (aux[x])
			{
//				printf("esto es aux en %i: %i y esto es la lista:%i y esto len:%i\n",x, aux[x], list->a[0], len);
//				usleep(100000);
				if (list->a[0] == aux[x])
				{
					push_b(list);
					check_pos(list, mid, list->b[0]);
					x = 0;
					len--;
				}
				x++;
			}
			if (len == 0)
				break ;
			rotate_a(list);
		}
	}
}

int	first_push(t_struct *list, int mid, int *aux)
{
	int	i;
	int	x;
	int	sum;

	i = 0;
	sum = 0;
	while(i <= mid)
	{
		x = 0;
		while(aux[x]) 
		{
			if (list->a[i] == aux[x])
				sum++;
			x++;
		}
		i++;;
	}
	while(list->a[i])
	{
		x = 0;
		while(aux[x]) 
		{
			if (list->a[i] == aux[x])
				sum--;
			x++;
		}
		i++;;
	}
	if (sum < 0)
		return (0); //esta en la mitad inferior
	return (1); //esta en la mitad superior
}

int	calculate_chunk(t_struct *list)
{
	int	i;

	i = list->index_a;
	if (i > 5 && i < 50)
		return (5);
	if (i >= 50 && i < 150)
		return (10);
	if (i >= 150 && i < 250)
		return (15);
	if (i >= 250 && i < 350)
		return (20);
	return (25);
}
//		sleep(5);

int *create_ordered_list(t_struct *list, int chunk_size, int chunknum, int *aux) //revisar para equilibrar mas aux un numero menos donde se resta
                                                                          //o un numero mas donde se suma
{
    int i;
    int x;
    int j;
    int k;

    i = list->index_a;
    j = chunk_size * chunknum;
    x = 0;
    k = 0;
    if (aux == NULL)
        aux = malloc(sizeof(int) * ((chunk_size * 2) + 1));
    else
    {
        free(aux);
        aux = malloc(sizeof(int) * ((chunk_size * 2) + 1));
    }
    while (x < i)
    {
		if (list->a[x] < (list->mid + j) && list->a[x] > (list->mid - j) && (list->a[x] >= 0 && list->a[x] < list->max))
        {
//			usleep(100000);
            aux[k] = list->a[x];
            k++;
        }
        x++;
    }
	aux[k] = (int)NULL;
    return (aux);
}

int	*last_ordered_list(t_struct *list, int *aux, int chunk_size)
{
	int	i;
	int	x;

	i = list->index_a;
	x = 0;
	free(aux);
	aux = malloc(sizeof(int) * ((chunk_size * 2) + 1));
	while (i > 0)
	{
		aux[x] = list->a[x];
		x++;
		i--;
	}
	return (aux);
}

void	algo_small(t_struct *list)
{
	int	*nums;
	int	chunk_size;
	int	count;
	int	i;
	int	x;
	int	k;

	nums = NULL;
	x = 1;
	list->mid = (list->index_a / 2);
	chunk_size = calculate_chunk(list);
	count = list->index_a / chunk_size;
	while (count > 0)
	{
		nums = create_ordered_list(list, chunk_size, x, nums);
		i = first_push(list, list->mid, nums);
		pusheo(list, i, nums, list->mid);
		k = 0;
		/*while (nums[k])
		{
			printf("esto es :%i en %i\n", nums[k], k);
			k++;
		}*/
		x++;
		count--;
	}
	nums = last_ordered_list(list, nums, chunk_size);
	while (nums[k])
	{
		sleep(10);
		printf("esto es :%i en %i\n", nums[k], k);			
		k++;
	}
	i = first_push(list, list->mid, nums);
	pusheo(list, i, nums, list->mid);
}
