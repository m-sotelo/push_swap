/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:22:46 by msotelo-          #+#    #+#             */
/*   Updated: 2022/10/17 21:09:25 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*-------------------------LIST-------------------------*/

typedef struct s_struct
{
	int	*a;
	int	*b;
	int	index_a;
	int	index_b;
	int	mid;
	int	max;
	int	check;
	int	pos1;
	int	pos2;
	int	order;
}	t_struct;

/*-------------------------FUNCTIONS-------------------------*/

void	free_list(t_struct *list);
void	free_aux(char **aux);
int		fill_list(int argc, char **argv, t_struct *list, int check);
int		check_numbers(t_struct *list);
void	push_a(t_struct *list);
void	push_b(t_struct *list);
void	map_list(t_struct *list);
void	ft_strdup_struct(t_struct *list, t_struct *aux);
void	map_list_2(t_struct *list, int *k);
void	swap_a(t_struct *list);
void	swap_b(t_struct *list);
void	swap_swap(t_struct *list);
void	rotate_a(t_struct *list);
void	rotate_b(t_struct *list);
void	rotate_rotate(t_struct *list);
void	reverse_rotate_a(t_struct *list);
void	reverse_rotate_b(t_struct *list);
void	reverse_reverse(t_struct *list);
void	init_list(t_struct *list, int x);
void	order_size(t_struct *list);
void	algo_2_a(t_struct *list);
void	algo_3_a(t_struct *list);
void	algo_2_b(t_struct *list);
void	algo_3_b(t_struct *list);
void	algo_4(t_struct *list);
void	algo_5(t_struct *list);
void	algo_small(t_struct *list);
void	remalloc(t_struct *list);
void	algo_small_back(t_struct *list);
void	pusheo(t_struct *list, int i, int mid);
int		check_pos(t_struct *list, int mid, int num);
int		first_push(t_struct *list, int mid, int *aux);
void	last_pusheo(t_struct *list, int mid);
void	write_null(t_struct *list);
int		first_check(int argc, char **argv);
void	init_list(t_struct *list, int x);
int		aux_len(int *aux);
#endif
