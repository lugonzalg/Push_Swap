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
#include "Libft/include/ft_printf.h"

void	sort_list_a(t_data *data)
{
	int	pos;
	int	i;
	char	*ref;
	char	*check;

	ref = (char *)data->head_a->content;
	i = 0;
	ft_printf("DIGIT: %d", data->digit);
	while (i < 9 && data->head_a)
	{
		pos = ft_strlen(data->head_a->content) - data->digit;
		if (pos < 0)
			pos += data->digit;
		check = (char *)data->head_a->content;
		ft_printf("POS: %d -- %c", pos, check[pos]);
		if (check[pos] == (i + 48) || !check[pos])
		{
			if (data->head_a->next && ref == data->head_a->content)
				ref = (char *)data->head_a->next->content;
			push_to_b(&data);
			continue ;
		}
		else if (data->head_a->next)
			rotate_a(&data);
		if (ref == (char *)data->head_a->content)
		{
			//digit++;
			i++;
		}
	}
	//printf_list(*data, "[A]SORT LIST", &data->processes);
	data->digit++;
}

void	sort_list_b(t_data *data)
{
	int	pos;
	int	i;
	char	*ref;
	char	*check;

	ref = (char *)data->head_b->content;
	i = 9;
	ft_printf("DIGIT: %d", data->digit);
	while (i > 0 && data->head_b)
	{
		pos = ft_strlen(data->head_b->content) - data->digit;
		if (pos < 0)
			pos += data->digit;
		check = (char *)data->head_b->content;
		ft_printf("POS: %d -- %c", pos, check[pos]);
		if (check[pos] == (i + 48) || !check[pos])
		{
			if (data->head_b->next && ref == data->head_b->content)
				ref = (char *)data->head_b->next->content;
			push_to_a(&data);
			continue ;
		}
		else if (data->head_b->next)
			rotate_b(&data);
		if (ref == (char *)data->head_b->content)
		{
			//digit++;
			i--;
		}
	}

	//while (data->head_b)
	//	push_to_a(&data);
	//printf_list(*data, "[B]SORT LIST", &data->processes);
}
