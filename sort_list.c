/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:01:10 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/24 18:01:11 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/libft.h"
#include "Libft/include/new_tools.h"
#include "Libft/include/ft_printf.h"

void	arr_upd(t_data *data, int *n, char type)
{
	if (type == 'a')
	{
		free(data->un);
		data->un = ft_lst_int(data->head_a, &data->size_u);
		free(data->arr);
		data->arr = ft_lst_int(data->head_a, &data->size_arr);
		ft_sort_arr(&data->arr, data->size_arr);
		(*n) = ft_findaprox(data->un, data->size_u, data->mid);
	}
	else
	{
		free(data->un);
		data->un = ft_lst_int(data->head_b, &data->size_u);
		free(data->arr);
		data->arr = ft_lst_int(data->head_b, &data->size_arr);
		ft_sort_arr(&data->arr, data->size_arr);
		(*n) = ft_findaprox(data->un, data->size_u, data->mid);
	}
}

void	multi_option(t_data *data)
{
	while (ft_findaprox(data->un, data->size_u, data->mid) != -1)
	{
		if ((int)data->head_a->content < data->mid)
			push_to_b(&data);
		else if ((int)data->tail_a->content < data->mid)
		{
			reverse_rotate_a(&data);
			push_to_b(&data);
		}
		else
		{
			if (data->n < data->size_u / 2)
			{
				while (data->n--)
					rotate_a(&data);
			}
			else
			{
				while (data->n--)
					reverse_rotate_a(&data);
			}
		}
		arr_upd(data, &data->n, 'a');
	}
}

void	sort_list_a(t_data *data)
{
	data->mid = data->arr[data->size_arr / 2];
	data->n = ft_findarr(data->un, data->size_u, data->mid);
	multi_option(data);
	if (ft_lstsize(data->head_a) == 2)
	{
		//ft_printf("ENDDD");
		if ((int)data->head_a->content > (int)data->head_a->next->content)
			rotate_a(&data);
	}
}

void	sort_list_b(t_data *data)
{
	int	moves;

	moves = 0;
	data->mid = data->arr[data->size_u - 1];
	data->n = ft_findarr(data->un, data->size_u, data->mid);
	if (data->n > data->size_u / 2)
	{
		while ((int)data->head_b->content != data->mid)
			reverse_rotate_b(&data);
	}
	else
	{
		while ((int)data->head_b->content != data->mid)
		{
			moves++;
			rotate_b(&data);
		}
	}
	push_to_a(&data);
	while (0 && moves--)
		reverse_rotate_b(&data);
	arr_upd(data, &data->n, 'b');

}
	//PRINTFTEDERO
	//ft_printf("DATA -> | N: %d | MAX: %d", data->n, data->mid);
	//ft_printf("N: %d -- SIZE_ARR: %d -- SIZE_ARR / 2: %d", data->n, data->size_arr, data->size_arr / 2);
	//ft_printf("N: %d", data->n);
	//ft_printf("SIZE_U: %d", data->size_u);
	//ft_printf("MID: %d", data->mid);
	//ft_printf("\nHEEEEEEEEEEEEEEEEEEEEEY\n\n");
	//ft_printf("\n2 - HEEEEEEY");
	//ft_printf("\n3 - HEEEEEEY");
	//ft_printf("\n\033[1;34mN: %d -- SIZE / 2: %d\033[0;m", n, data->size_u / 2);
	//ft_printf("OLE");
	//ft_printf("ELO");
	//printf_list((*data), "ALL SET", &(*data).processes);
	//printf_list((*data), "END_LOOP", &(*data).processes);
	//printf_list((*data), "ON_MOVES", &(*data).processes);
	//
	//VERTEDERO
	//else if ((int)data->head_a->content < data->mid)
	//	rotate_a(&data);
	//
	//else if ((int)data->head_a->next->content < data->mid)
	//else if ((int)data->head_a->next->content < data->mid)
	//{
	//	swap_a(&data);
	//	push_to_b(&data);
	//}
	//{
	//	swap_a(&data);
	//	push_to_b(&data);
	//}
	//
	//else
	//	back_option(data);
	/*
	{
		while (data->n--)
			{
			if ((int)data->tail_a->content < data->mid)
			{
				reverse_rotate_a(&data);
				push_to_b(&data);
			}
			else if ((int)data->head_a->content < data->mid)
				push_to_b(&data);
		}
	}*/
	//if (data->n <= data->size_u / 2)
	//arr_upd(data, &data->n);
