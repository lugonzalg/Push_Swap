/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:14:06 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/22 17:14:34 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_data {
	struct s_list	*head_a;
	struct s_list	*head_b;
	struct s_list	*tail_a;
	struct s_list	*tail_b;
	struct s_list	*list;
	char			**tab;
	int				signal;
	int				min;
	char			*num;
//	intptr_t		num;
	int				processes;
	int				digit;
}	t_data;

void	printf_list(t_data data, char *str, int *processes);

void	sort_list_a(t_data *data);
void	sort_list_b(t_data *data);

void	swap_a(t_data **data);
void	swap_b(t_data **data);
void	double_swap(t_data **data);
void	rotate_a(t_data **data);
void	rotate_b(t_data	**data);
void	push_to_b(t_data **data);
void	push_to_a(t_data **data);
void	reverse_rotate_a(t_data **data);
void	reverse_rotate_b(t_data **data);
void	double_reverse_rotate(t_data **data);
#endif
