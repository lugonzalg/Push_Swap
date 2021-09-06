/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:20:04 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 20:21:32 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/libft.h"
#include "Libft/include/new_tools.h"
#include "Libft/include/ft_printf.h"

void	create_chunk(t_data *data, int value)
{
	while (data->head_a)
	{
		data->chunk += value + 1;
		if (data->size_u < value)
			data->chunk = data->size_u;
		if (data->size_u == 1)
			data->chunk = 2;
		while (--data->chunk && data->size_u)
		{
			if (data->size_u == value)
				data->chunk--;
			if (data->size_u > 1 && check_pos(data, 1))
			{
				while ((int)data->head_a->content >= data->arr[data->chunk])
					rotate_a(&data);
			}
			else if (data->size_u > 1 && data->chunk)
			{
				while ((int)data->head_a->content >= data->arr[data->chunk])
					reverse_rotate_a(&data);
			}
			push_to_b(&data);
			arr_upd(data, 'a');
		}
	}
}

void	sort_3(t_data *data)
{
	while (check_sort(data))
	{
		if ((int)data->head_a->content > (int)data->head_a->next->content
			&& (int)data->head_a->content < (int)data->tail_a->content)
			swap_a(&data);
		else if ((int)data->head_a->content < (int)data->head_a->next->content
			&& (int)data->head_a->content < (int)data->tail_a->content)
			reverse_rotate_a(&data);
		else if ((int)data->head_a->content < (int)data->head_a->next->content
			&& (int)data->head_a->content > (int)data->tail_a->content)
			reverse_rotate_a(&data);
		else if ((int)data->head_a->content > (int)data->head_a->next->content
			&& (int)data->head_a->content > (int)data->tail_a->content)
			rotate_a(&data);
	}
}
