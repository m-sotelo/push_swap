/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:14:58 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/26 19:22:58 by msotelo-         ###   ########.fr       */
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

int	aux_aux(int k, int len, char **tmp, char *argv)
{
	tmp = ft_split(argv, ' ');
	while (tmp[k] != NULL)
	{
		k++;
		len++;
	}
	free_aux(tmp);
	return (len);
}

int	first_check_2(char **argv, char **tmp, int j, int argc)
{
	int	k;
	int	i;
	int	len;
	int	check;

	len = 0;
	while (j < argc)
	{
		i = 0;
		check = 0;
		while ((argv[j][i] != '\0') && (argv[j] != NULL))
		{
			k = 0;
			if (argv[j][i] == ' ')
				check = 1;
			if ((argv[j][i] >= 49 && argv[j][i] <= 57) && check == 1)
				len = aux_aux(k, len, tmp, argv[j]);
			i++;
		}
		j++;
		len++;
	}
	return (len);
}

int	first_check(int argc, char **argv)
{
	char	**tmp;
	int		len;
	int		j;

	j = 0;
	len = 0;
	tmp = NULL;
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
		len = first_check_2(argv, tmp, j, argc);
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
