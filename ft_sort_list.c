/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:19:56 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 20:19:58 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/libft.h"
#include "Libft/include/new_tools.h"
#include "Libft/include/ft_printf.h"

void	sort_100(t_data *data)
{
	arr_upd(data, 'b');
	while (data->head_b)
	{
		if (check_pos(data, 0))
		{
			while ((int)data->head_b->content != data->arr[data->size_arr - 1])
				rotate_b(&data);
		}
		else
		{
			while ((int)data->head_b->content != data->arr[data->size_arr - 1])
				reverse_rotate_b(&data);
		}
		push_to_a(&data);
		arr_upd(data, 'b');
	}	
}

int	check_sort(t_data *data)
{
	t_list	*tmp;

	tmp = data->head_a;
	while (tmp->next)
	{
		if ((int)tmp->content > (int)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	multi_option(t_data *data)
{
	while (ft_findaprox(data->un, data->size_u, data->mid) != -1)
	{
		data->n = ft_findaprox(data->un, data->size_u, data->mid);
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
		arr_upd(data, 'a');
	}
}

void	sort_list_a(t_data *data)
{
	data->mid = data->arr[data->size_arr / 2];
	data->n = ft_findarr(data->un, data->size_u, data->mid);
	multi_option(data);
	sort_3(data);
	if (ft_lstsize(data->head_a) == 2)
	{
		if ((int)data->head_a->content > (int)data->head_a->next->content)
			rotate_a(&data);
	}
	sort_list_b(data);
}

void	sort_list_b(t_data *data)
{
	while (data->head_b)
	{
		arr_upd(data, 'b');
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
				rotate_b(&data);
		}
		push_to_a(&data);
	}
}
