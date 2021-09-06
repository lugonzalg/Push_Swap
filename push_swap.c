/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:14:43 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/22 17:15:01 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "Libft/include/libft.h"
#include "Libft/include/new_tools.h"
#include "Libft/include/ft_printf.h"
#include "push_swap.h"

intptr_t	atoi_alert(const char *str, int *signal)
{
	long	out;
	int		neg;

	neg = 1;
	out = 0;
	if (str[0] == '-')
	{
		str++;
		neg = -1;
	}
	while (*str)
	{
		out = out * 10 + (*str - 48);
		if (!ft_isdigit(*str)
			|| out * neg > 2147483647 || out * neg < -2147483648)
		{
			*signal = 1;
			return (0);
		}
		str++;
	}
	return (out * neg);
}

char	*check_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (NULL);
		i++;
	}
	return (str);
}

int	set_value(t_data *data)
{
	int	n;

	n = ft_lstsize(data->head_a);
	if (n >= 100 && n < 500)
		return (20);
	else if (n < 100 && n > 6)
		return (10);
	else if (n >= 500)
		return (35);
	return (10);
}

void	free_list(t_data *data)
{
	while (data->head_a)
	{
		data->list = data->head_a;
		data->head_a = data->head_a->next;
		free(data->list);
	}
	free(data->arr);
	free(data->un);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.signal = 0;
		if (argc == 2)
			create_list(ft_split(argv[1], ' '), &data, 1);
		else
			create_list(++argv, &data, 0);
		set_arr(&data, 'a');
		if (ft_lstsize(data.head_a) < 4)
			sort_3(&data);
		else if (ft_lstsize(data.head_a) < 6)
			sort_list_a(&data);
		else
		{
			create_chunk(&data, set_value(&data));
			sort_100(&data);
		}
		free_list(&data);
		//system("leaks push_swap");
	}
}
