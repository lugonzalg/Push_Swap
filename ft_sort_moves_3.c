/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_moves_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:49:35 by lugonzal          #+#    #+#             */
/*Updated: 2021/09/06 19:49:37 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/include/libft.h"
#include "Libft/include/ft_printf.h"
#include "Libft/include/new_tools.h"

void	reverse_rotate_a(t_data **data)
{
	if ((*data)->head_a->next)
		ft_lsttail_front(&(*data)->head_a, &(*data)->tail_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_data **data)
{
	if ((*data)->head_b->next)
		ft_lsttail_front(&(*data)->head_b, &(*data)->tail_b);
	ft_printf("rrb\n");
}

void	double_reverse_rotate(t_data **data)
{
	if ((*data)->head_a->next)
		ft_lsttail_front(&(*data)->head_a, &(*data)->tail_a);
	if ((*data)->head_b->next)
		ft_lsttail_front(&(*data)->head_b, &(*data)->tail_b);
	ft_printf("rrr\n");
}
