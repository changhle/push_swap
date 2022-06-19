/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:32:29 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 12:53:42 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_var(t_var *var)
{
	var->ra_cnt = 0;
	var->rb_cnt = 0;
	var->pa_cnt = 0;
	var->pb_cnt = 0;
}

void	init_info(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
	info->cmd = 0;
	info->a_top = NULL;
	info->a_bottom = NULL;
	info->b_top = NULL;
	info->b_bottom = NULL;
}

void	push_to_stack_command(t_info *info, char *str)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->command = str;
	temp->next = NULL;
	temp->prev = NULL;
	if (info->cmd_top)
	{
		info->cmd_bottom->next = temp;
		temp->prev = info->cmd_bottom;
		info->cmd_bottom = temp;
	}
	else
	{
		info->cmd_top = temp;
		info->cmd_bottom = temp;
	}
}

void	push_to_stack_a(char *arr, t_info *info)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (ft_atoll(arr) == 2147483648)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	temp->content = ft_atoll(arr);
	temp->next = NULL;
	temp->prev = NULL;
	if (info->a_size > 0)
	{
		info->a_bottom->next = temp;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top = temp;
		info->a_bottom = temp;
	}
	info->a_size++;
}
