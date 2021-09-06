/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:29:28 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 19:29:29 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/new_tools.h"

int	check_pos(t_data *data, int on)
{
	int	u;
	int	l;

	if (on)
	{
		u = ft_findaprox(data->un, data->size_u, data->arr[data->chunk]);
		l = ft_findaproxb(data->un, data->size_u, data->arr[data->chunk]);
		if (u == -1 && l == -1)
		{
			data->chunk = 1;
			return (0);
		}
		if (u <= l)
			return (1);
		return (0);
	}
	else
	{
		u = ft_findarr(data->un, data->size_u, data->arr[data->size_arr - 1]);
		l = ft_findarrb(data->un, data->size_u, data->arr[data->size_arr - 1]);
		if (u <= l)
			return (1);
		return (0);
	}
}
