/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:14:58 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/17 21:05:01 by msotelo-         ###   ########.fr       */
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

int	first_check_2(char **argv, char **tmp, int j, int check)
{
	int	k;
	int	i;
	int	len;

	len = 0;
	while (argv[j++])
	{
		i = -1;
		check = 0;
		while (argv[j][i++] != '\0')
		{
			k = -1;
			if (argv[j][i] == ' ')
				check = 1;
			if ((argv[j][i] >= 49 && argv[j][i] <= 57) && check == 1)
			{
				tmp = ft_split(argv[j], ' ');
				while (tmp[k++])
					len++;
				free_aux(tmp);
			}
		}
		len++;
	}
	return (len);
}

int	first_check(int argc, char **argv)
{
	char	**tmp;
	int		len;
	int		j;
	int		check;

	j = -1;
	len = 0;
	tmp = NULL;
	check = 0;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[len])
			len++;
		free_aux(tmp);
	}
	else
		len = first_check_2(argv, tmp, j, check);
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
