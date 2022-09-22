/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:14:58 by msotelo-          #+#    #+#             */
/*   Updated: 2022/09/23 01:11:48 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	write_null(t_struct *list)
{
	int	i;

	i = list->index_a;
	list->a[i] = (int) NULL;
	list->b[i] = (int) NULL;
}

int	first_check(int argc, char **argv)
{
	char	**tmp;
	int		len;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		len = 0;
		tmp = ft_split(argv[1], ' ');
		while (tmp[len])
			len++;
		free_aux(tmp);
	}
	else
		len = argc - 1;
	return (len);
}

void	init_list(t_struct *list, int x)
{
	list->a = malloc(sizeof(int) * (x + 1));
	list->b = malloc(sizeof(int) * (x + 1));
	list->index_a = 0;
	list->index_b = 0;
	return ;
}
