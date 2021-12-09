/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:09:12 by msotelo-          #+#    #+#             */
/*   Updated: 2021/12/09 14:42:10 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_aux(char **aux)
{
	int	i;

	i = 0;
	while(aux[i])
	{
		free(aux[i]);
		i++;
	}
	free (aux);
}

int	check_entry(char **aux)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(aux[i])
	{
		j = 0;
		while(aux[i][j])
		{
			if((aux[i][j] == '+' || aux[i][j] == '-') && (ft_isdigit(aux[i][j + 1]) == 0))
				return (0);
			else if((ft_isdigit(aux[i][j]) == 0) && (aux[i][j] != ' ' && aux[i][j] != '+' && aux[i][j] != '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_list(int argc, char **argv, t_struct *list)
{
	int		i;
	int		j;
	int		k;
	int		s;
	char	**aux;

	j = 0;
	i = 1;
	while (i < argc)
	{
		k = 0;
		aux = NULL;
		aux = ft_split(argv[i], ' ');
		while (aux[k])
		{
			s = check_entry(aux);
			if (s == 0)
			{
				return (0);
			}
			list->a[j] = ft_atoi(aux[k]);
			j++;
			k++;
			list->index_a++;
		}
		free_aux(aux);
		i++;
	}
	return (1);
}
