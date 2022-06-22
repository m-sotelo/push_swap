/*void	choose1(t_struct *list)//funciones para elegir cual tiene prieoridad
							   //para hacer un semi orden mejr antes de ordenar
							   //de verdad.
{

}*/

void	rrotate_for_rrotate(t_struct *list)
{
	int	a;
	int	b;
	
	a = list->index_a;
	b = list->index_b;
	if (list->a[0] > list->a[a - 1] && list->b[0] > list->b[b - 1])
	{
		reverse_reverse(list);
		return ;
	}
	else if (list->a[0] > list->a[a - 1])
	{
		reverse_rotate_a(list);
		return ;
	}
	else if (list->b[0] > list->b[b - 1])
	{
		reverse_rotate_b(list);
		return ;
	}
	return ;
}

void	rotate_for_rotate(t_struct *list)
{
	if (list->a[2] > list->a[1] && list->b[2] > list->b[1])
	{
		rotate_rotate(list);
		return ;
	}
	else if (list->a[2] > list->a[1])
	{
		rotate_a(list);
		return ;
	}
	else if (list->b[2] > list->b[1])
	{
		rotate_b(list);
		return ;
	}
	return ;
}

void	rotate_for_swap(t_struct *list)
{
	if (list->a[2] < list->a[1] && list->b[2] < list->b[1])
	{
		rotate_rotate(list);
		return ;
	}
	else if (list->a[2] < list->a[1])
	{
		rotate_a(list);
		return ;
	}
	else if (list->b[2] < list->b[1])
	{
		rotate_b(list);
		return ;
	}
	return ;
}

void	rrotate_for_swap(t_struct *list)
{
	int	a;
	int	b;
	
	a = list->index_a;
	b = list->index_b;
	if (list->a[0] < list->a[a - 1] && list->b[0] < list->b[b - 1])
	{
		reverse_reverse(list);
		return ;
	}
	else if (list->a[0] < list->a[a - 1])
	{
		reverse_rotate_a(list);
		return ;
	}
	else if (list->b[0] < list->b[b - 1])
	{
		reverse_rotate_b(list);
		return ;
	}
	return ;
}

void	first_swap(t_struct *list)
{	
	if (list->a[0] > list->a[1] && list->b[0] > list->b[1])
	{
		swap_swap(list);
		return ;
	}	
	else if (list->a[0] > list->a[1])
	{
		swap_a(list);
		return ;
	}
	else if (list->b[0] > list->b[1])
	{
		swap_b(list);
		return ;
	}
	return ;
}

void	first_push(t_struct *list, int i, int piv)
{
	int x;

	x = 0;
	if (piv < (i/2 - 1))
	{
		while(x < i)
		{
			rotate_a(list);
			if(list->a[0] <= i/2)
				push_b(list);
			x++;
		}
	}
	else
	{
		while(x < i)
		{
			reverse_rotate_a(list);
			if(list->a[0] <= i/2)
				push_b(list);
			x++;
		}
	}
	return ;
}

int	find_pivot(t_struct *list, int i)
{	
	int	x;
	int	piv;

	x = 0;
	while(x < i)
	{
		if (list->a[x] == (i/2))
			piv = x;
		x++;
	}
	return (piv);
}

void	start_solve(t_struct *list, int check_size, int i)
{
	int	piv;

	check_size = 0,
	piv = find_pivot(list, i);
	first_push(list, i, piv);
	while (check_size < 10)
	{
		first_swap(list);
		rrotate_for_swap(list);
		first_swap(list);
		rotate_for_swap(list);
		first_swap(list);
		rrotate_for_rrotate(list);
		rotate_for_rotate(list);
		check_size++;
	}
}

void	algo_small(t_struct *list)
{
	int	i;
	int check_size;

	i = list->index_a;
	check_size = 0;
	if (i <= 25)
		check_size = 1;
	else if (i > 25 && i <= 50)
		check_size = 02;
	else if (i > 50 && i <= 75)
		check_size = 3;
	else if (i > 75 && i <= 100)
		check_size = 4;
	start_solve(list, check_size, i);
	return ;
}
