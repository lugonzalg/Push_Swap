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
		if (!ft_isdigit(*str) || out > 2147483647 || out < -2147483648)
		{
			*signal = 1;
			return ((uintptr_t)0);
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
		if(!ft_isdigit(str[i]))
			return (NULL);
		i++;
	}
	return (str);
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

void	create_list(char **tab, t_data *data)
{
	int	i;

	init_refs(&data);
	i = -1;
	while (tab[++i])
	{
		data->num = atoi_alert(tab[i], &data->signal);
		//data->num = check_num(tab[i]);
		if (data->signal)
		{
			ft_printf("ERROR %d -- %s\n", i, tab[i]);
			//ft_printf("SIGNAL ABORT_0\n");
			//ft_lstclear(data->head_a, NULL);
			exit (0);
		}
		data->list = ft_lstnew((void *)data->num);
		ft_lstadd_backtail(&data->head_a, data->list, &data->tail_a);
	}
}

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

int	main(int argc, char **argv)
{
	t_data	data;

	data.processes = 0;
	if (argc > 1)
	{
		data.signal = 0;
		if (argc == 2)
		{
			data.tab = ft_split(argv[1], ' ');
			create_list(data.tab, &data);
		}
		else
			create_list(++argv, &data);
		set_arr(&data, 'a');
		while (data.head_a->next->content != data.tail_a->content)
			sort_list_a(&data);
		set_arr(&data, 'b');
		while (data.head_b)
			sort_list_b(&data);
	}
	return (1);
}
