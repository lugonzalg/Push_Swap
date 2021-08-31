/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail_fron.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:51:05 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/23 18:52:15 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	ft_lsttail_front(t_list **lst, t_list **tail)
{
	t_list	*tmp;
	t_list	*head_ref;

	head_ref = (*lst);
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	tmp = (*lst)->next;
	tmp->next = head_ref;
	(*lst)->next = NULL;
	(*tail) = (*lst);
	(*lst) = tmp;
}
