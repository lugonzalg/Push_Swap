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
	//printf_list(**data, "PRE_SWAP_A", &(*data)->processes);
	if ((*data)->head_a)
	{
		(*data)->list = (*data)->head_a->next;
		(*data)->head_a->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_a;
		(*data)->head_a = (*data)->list;
	}
	printf_list(**data, "POST_SWAP_A", &(*data)->processes);
	ft_printf("sa\n");
}

void	swap_b(t_data **data)
{
	//printf_list(**data, "PRE_SWAP_B", &(*data)->processes);
	if ((*data)->head_b)
	{
		(*data)->list = (*data)->head_b->next;
		(*data)->head_b->next = (*data)->list->next;
		(*data)->list->next = (*data)->head_b;
		(*data)->head_b = (*data)->list;
	}
	printf_list(**data, "POST_SWAP_B", &(*data)->processes);
	ft_printf("sb\n");
}

void	double_swap(t_data **data)
{
	swap_a(data);
	swap_b(data);
}

void	rotate_a(t_data **data)
{
	(*data)->list = (*data)->head_a->next;
	//printf_list(**data, "PRE_ROTATE_A", &(*data)->processes);
	ft_lstadd_backtail(&(*data)->head_a, (*data)->head_a, &(*data)->tail_a);
	(*data)->head_a = (*data)->list;
	printf_list(**data,"POST_ROTATE_A", &(*data)->processes);
	ft_printf("ra\n");
}

void	rotate_b(t_data **data)
{
	(*data)->list = (*data)->head_b->next;
	//printf_list(**data, "PRE_ROTATE_B", &(*data)->processes);
	ft_lstadd_backtail(&(*data)->head_b, (*data)->head_b, &(*data)->tail_b);
	(*data)->head_b = (*data)->list;
	printf_list(**data,"POST_ROTATE_B", &(*data)->processes);
	ft_printf("rb\n");
}

void	push_to_b(t_data **data)
{
	//printf_list(**data,"PRE_PUSH_TO_B", &(*data)->processes);
	(*data)->list = (*data)->head_a->next;
	ft_lstadd_front(&(*data)->head_b, (*data)->head_a);
	(*data)->head_a = (*data)->list;
	if (!(*data)->tail_b)
		(*data)->tail_b = (*data)->head_b;
	printf_list(**data,"POST_PUSH_TO_B", &(*data)->processes);
	ft_printf("pb\n");
}

void	push_to_a(t_data **data)
{
	//printf_list(**data,"PRE_PUSH_TO_A", &(*data)->processes);
	(*data)->list = (*data)->head_b->next;
	ft_lstadd_front(&(*data)->head_a, (*data)->head_b);
	(*data)->head_b = (*data)->list;
	if (!(*data)->tail_a)
		(*data)->tail_a = (*data)->head_a;
	printf_list(**data,"POST_PUSH_TO_A", &(*data)->processes);
	ft_printf("pa\n");
}

void	double_rotate(t_data **data)
{
	rotate_a(data);
	rotate_b(data);
}

void	reverse_rotate_a(t_data **data)
{
	//printf_list(**data, "PRE_REVERSE_ROTATE_A", &(*data)->processes);
	if ((*data)->head_a->next)
		ft_lsttail_front(&(*data)->head_a, &(*data)->tail_a);
	printf_list(**data, "PRE_REVERSE_ROTATE_A", &(*data)->processes);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_data **data)
{
	//printf_list(**data, "PRE_REVERSE_ROTATE_B", &(*data)->processes);
	if ((*data)->head_b->next)
		ft_lsttail_front(&(*data)->head_b, &(*data)->tail_b);
	printf_list(**data, "POST_REVERSE_ROTATE_B", &(*data)->processes);
	ft_printf("rrb\n");
}

void	double_reverse_rotate(t_data **data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}
//ft_printf("\nCONTENT_LIST: %d\n", (int)(*data)->list->content);
//ft_printf("NEXT_CONTENT_LIST: %d\n", (int)(*data)->list->next->content);
//ft_printf("CONTENT_HEaD: %d\n", (int)(*data)->head_a->content);
//ft_printf("\nCONTENT_LIST: %d\n", (int)(*data)->list->content);
//ft_printf("CONTENT_HEaD: %d\n", (int)(*data)->head_a->content);
