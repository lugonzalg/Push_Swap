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

# include <stdlib.h>

typedef struct s_data {
	struct s_list	*head_a;
	struct s_list	*head_b;
	struct s_list	*tail_a;
	struct s_list	*tail_b;
	struct s_list	*list;
	struct s_list	*pivot;
	intptr_t		num;
	int				signal;
	int				mid;
	int				n;
	int				chunk;
	int				*arr;
	int				*un;
	int				size_u;
	int				size_arr;
}	t_data;

void		printf_list(t_data data, char *str, int *processes);

void		sort_list_a(t_data *data);
void		sort_list_b(t_data *data);

void		create_chunk(t_data *data, int value);
void		sort_100(t_data *data);
void		sort_3(t_data *data);
void		create_chunk(t_data *data, int value);
void		set_arr(t_data *data, char type);
void		arr_upd(t_data *data, char type);
int 		check_sort(t_data *data);
int			check_pos(t_data *data, int on);
intptr_t	atoi_alert(const char *str, int *signal);

void		create_list(char **tab, t_data *data, int on);
void		swap_a(t_data **data);
void		swap_b(t_data **data);
void		double_swap(t_data **data);
void		rotate_a(t_data **data);
void		rotate_b(t_data	**data);
void		push_to_b(t_data **data);
void		push_to_a(t_data **data);
void		reverse_rotate_a(t_data **data);
void		reverse_rotate_b(t_data **data);
void		double_reverse_rotate(t_data **data);
void		double_rotate(t_data **data);
#endif
