/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:41:57 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 19:41:59 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/include/libft.h"
#include "Libft/include/ft_printf.h"
#include "push_swap.h"

void	push_to_a(t_data **data)
{
	(*data)->list = (*data)->head_b->next;
	ft_lstadd_front(&(*data)->head_a, (*data)->head_b);
	(*data)->head_b = (*data)->list;
	if (!(*data)->tail_a)
		(*data)->tail_a = (*data)->head_a;
	ft_printf("pa\n");
}

void	push_to_b(t_data **data)
{
	(*data)->list = (*data)->head_a->next;
	ft_lstadd_front(&(*data)->head_b, (*data)->head_a);
	(*data)->head_a = (*data)->list;
	if (!(*data)->tail_b)
		(*data)->tail_b = (*data)->head_b;
	ft_printf("pb\n");
}

void	double_rotate(t_data **data)
{
	(*data)->list = (*data)->head_b->next;
	ft_lstadd_backtail(&(*data)->head_b, (*data)->head_b, &(*data)->tail_b);
	(*data)->head_b = (*data)->list;
	ft_printf("rb\n");
	(*data)->list = (*data)->head_a->next;
	ft_lstadd_backtail(&(*data)->head_a, (*data)->head_a, &(*data)->tail_a);
	(*data)->head_a = (*data)->list;
	ft_printf("ra\n");
}


