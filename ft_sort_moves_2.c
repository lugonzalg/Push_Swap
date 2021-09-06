/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:45:47 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/22 19:51:53 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/include/libft.h"
#include "Libft/include/ft_printf.h"
#include "push_swap.h"

void	swap_a(t_data **data)
{
	if ((*data)->head_a)
	{
		(*data)->list = (*data)->head_a->next;
		(*data)->head_a->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_a;
		(*data)->head_a = (*data)->list;
	}
	ft_printf("sa\n");
}

void	swap_b(t_data **data)
{
	if ((*data)->head_b)
	{
		(*data)->list = (*data)->head_b->next;
		(*data)->head_b->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_b;
		(*data)->head_b = (*data)->list;
	}
	ft_printf("sb\n");
}

void	double_swap(t_data **data)
{
	if ((*data)->head_a)
	{
		(*data)->list = (*data)->head_a->next;
		(*data)->head_a->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_a;
		(*data)->head_a = (*data)->list;
	}
	if ((*data)->head_b)
	{
		(*data)->list = (*data)->head_b->next;
		(*data)->head_b->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_b;
		(*data)->head_b = (*data)->list;
	}
	ft_printf("ss\n");
}

void	rotate_a(t_data **data)
{
	(*data)->list = (*data)->head_a->next;
	ft_lstadd_backtail(&(*data)->head_a, (*data)->head_a, &(*data)->tail_a);
	(*data)->head_a = (*data)->list;
	ft_printf("ra\n");
}

void	rotate_b(t_data **data)
{
	(*data)->list = (*data)->head_b->next;
	ft_lstadd_backtail(&(*data)->head_b, (*data)->head_b, &(*data)->tail_b);
	(*data)->head_b = (*data)->list;
	ft_printf("rb\n");
}


