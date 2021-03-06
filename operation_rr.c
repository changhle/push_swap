/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:26 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:12:48 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rra(t_info *info)
{
	t_node	*temp;

	if (info->a_size > 1)
	{
		temp = info->a_bottom;
		info->a_bottom = info->a_bottom->prev;
		info->a_bottom->next = NULL;
		info->a_top->prev = temp;
		temp->next = info->a_top;
		temp->prev = NULL;
		info->a_top = temp;
	}
}

void	rrb(t_info *info)
{
	t_node	*temp;

	if (info->b_size > 1)
	{
		temp = info->b_bottom;
		info->b_bottom = info->b_bottom->prev;
		info->b_bottom->next = NULL;
		info->b_top->prev = temp;
		temp->next = info->b_top;
		temp->prev = NULL;
		info->b_top = temp;
	}
}

void	rrr(t_info *info)
{
	t_node	*temp;

	rra(info);
	rrb(info);
}
