/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:35:51 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 19:35:54 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/libft.h"
#include "Libft/include/new_tools.h"

void	set_arr(t_data *data, char type)
{
	if (type == 'a')
		data->arr = ft_lst_int(data->head_a, &data->size_arr);
	else
		data->arr = ft_lst_int(data->head_b, &data->size_arr);
	data->size_u = data->size_arr;
	data->un = ft_duparr(data->arr, data->size_arr);
	ft_sort_arr(&data->arr, data->size_arr);
}

void	arr_upd(t_data *data, char type)
{
	if (type == 'a')
	{
		free(data->un);
		data->un = ft_lst_int(data->head_a, &data->size_u);
		free(data->arr);
		data->arr = ft_lst_int(data->head_a, &data->size_arr);
		ft_sort_arr(&data->arr, data->size_arr);
	}
	else
	{
		free(data->un);
		data->un = ft_lst_int(data->head_b, &data->size_u);
		free(data->arr);
		data->arr = ft_lst_int(data->head_b, &data->size_arr);
		ft_sort_arr(&data->arr, data->size_arr);
	}
}

void	init_refs(t_data **data)
{
	(*data)->head_a = NULL;
	(*data)->head_b = NULL;
	(*data)->tail_a = NULL;
	(*data)->tail_b = NULL;
	(*data)->pivot = NULL;
	(*data)->list = NULL;
}

void	clear_list(t_data *data)
{
	while (data->head_a)
	{
		data->list = data->head_a;
		data->head_a = data->head_a->next;
		free(data->list);
	}	
}

void	create_list(char **tab, t_data *data, int on)
{
	int	i;

	init_refs(&data);
	i = -1;
	while (tab[++i])
	{
		data->num = atoi_alert(tab[i], &data->signal);
		if (data->signal)
			clear_list(data);
		data->list = ft_lstnew((void *)data->num);
		ft_lstadd_backtail(&data->head_a, data->list, &data->tail_a);
	}
	i = -1;
	while (on && tab[++i])
		free(tab[i]);
	if (on)
		free(tab);
}
