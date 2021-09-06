/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:04:26 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/30 17:04:29 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Libft/include/libft.h"
#include "Libft/include/ft_printf.h"
#include "push_swap.h"

void	printf_list(t_data data, char *str, int *processes)
{
	(*processes)++;
	int	i;

	ft_printf("\n\033[1;32m//////////////////////////////////////////\033[0;m\n");
	ft_printf("\033[1;32m\tSORT, DOING %s R: %d\033[0;m\n", str, (*processes));
	ft_printf("\033[1;32m//////////////////////////////////////////\033[0;m\n");
	if (data.pivot)
		ft_printf("\n\033[1;34mPIVOT_ %d\033[0;m", (int)data.pivot->content);
	if (data.head_a)
	{
		ft_printf("\n\033[1;34mHEAD_A_CONT: %d\033[0;m", (int)data.head_a->content);
		ft_printf("\t\t\033[1;34mHEAD_A_REF: %p\033[0;m\n", data.head_a);
		if (data.head_a->next)
		{
			ft_printf("\n\033[1;34mHEAD_A_NEXT_CONT: %d\033[0;m", (int)data.head_a->next->content);
			ft_printf("\t\t\033[1;34mHEAD_A_NEXT_REF: %p\033[0;m\n", data.head_a->next);
		}
		ft_printf("\n\033[1;34mTAIL_A_CONT: %d\033[0;m", (int)data.tail_a->content);
		ft_printf("\t\t\033[1;34mTAIL_A_REF: %p\033[0;m\n", data.tail_a);
		
	}
	else
		ft_printf("\n\033[1;34mhead_A_NULL: \033[0;m\n\n");
	if (data.head_b)
	{
		ft_printf("\n\033[1;34mHEAD_B_CONT: %d\033[0;m", (int)data.head_b->content);
		ft_printf("\t\t\033[1;34mHEAD_B_REF: %p\033[0;m\n", data.head_b);
		if (data.head_b->next)
		{
			ft_printf("\n\033[1;34mHEAD_B_NEXT_CONT: %d\033[0;m", (int)data.head_b->next->content);
			ft_printf("\t\t\033[1;34mHEAD_B_NEXT_REF: %p\033[0;m\n", data.head_b->next);
		}
		ft_printf("\n\033[1;34mTAIL_B_CONT: %d\033[0;m", (int)data.tail_b->content);
		ft_printf("\t\t\033[1;34mTAIL_B_REF: %p\033[0;m\n", data.tail_b);
	}
	else
		ft_printf("\n\033[1;34mhead_B_NULL: \033[0;m\n\n");
	ft_printf("\033[1;31m__________________________\033[0;m\n");
	ft_printf("\033[1;31m\tSORT A\033[0;m\n");
	ft_printf("\033[1;31m--------------------------\033[0;m\n");
	if (!data.head_a)
		ft_printf("\033[1;31m\tEMPTY\033[0;m\n");
	else
	{
		while (data.head_a)
		{
			//if ((int)data.head_a->content == data.mid)
			//	ft_printf("CONTENT:\t\033[1;31m[%d]\033[0;m\n", (int)data.head_a->content);
			//else
				ft_printf("CONTENT:\t%d\n",(int)data.head_a->content);
			data.head_a = data.head_a->next;
		}
	}
	ft_printf("\n\n\033[1;31m__________________________\033[0;m\n");
	ft_printf("\033[1;31m\tSORT B\033[0;m\n");
	ft_printf("\033[1;31m--------------------------\033[0;m\n");
	if (!data.head_b)
		ft_printf("\033[1;31m\tEMPTY\033[0;m\n");
	else
	{
		while (data.head_b)
		{
			ft_printf("CONTENT:\t%d\n",(int) data.head_b->content);
			data.head_b = data.head_b->next;
		}
	}
	ft_printf("\n\033[1;34mSIZE: %d\033[0;m", data.size_u);
	ft_printf("\n\033[1;34mMID_POS: %d\033[0;m", data.size_u / 2);
	ft_printf("\n\033[1;34mSIZE: %d\033[0;m", data.size_arr);
	ft_printf("\n\033[1;34mMID_POS: %d\033[0;m", data.size_arr / 2);
	//ft_printf("\n\033[1;34mMID_VALUE: %d\033[0;m", data.mid);
	if (data.arr)
	{
		ft_printf("\n\n\033[1;31m__________________________\033[0;m\n");
		ft_printf("\033[1;31m\tAUX ARR\033[0;m\n");
		ft_printf("\033[1;31m--------------------------\033[0;m\n");
		i = -1;
		while (++i < data.size_arr)
		{
			//if (data.mid == data.arr[i])
			//	ft_printf("AUX_CONTENT: \033[1;31m[%d]\033[0;m\n", data.arr[i]);
			//else
				ft_printf("AUX_CONTENT[%d]: %d\n", i, data.arr[i]);
		}
	}
	if (data.un)
	{
		ft_printf("\n\n\033[1;31m__________________________\033[0;m\n");
		ft_printf("\033[1;31m\tAUX DUP\033[0;m\n");
		ft_printf("\033[1;31m--------------------------\033[0;m\n");
		i = -1;
		while (++i < data.size_u)
		{
			//if (data.mid == data.un[i])
			//	ft_printf("AUX_CONTENT: \033[1;31m[%d]\033[0;m\n", data.un[i]);
			//else
				ft_printf("UNS_CONTENT[%d]: %d\n", i, data.un[i]);
		}
	}
}
