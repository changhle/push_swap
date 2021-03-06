/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:09:03 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 16:49:31 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	check_sort(t_node *node)
{
	while (node->next)
	{
		if (node->content > node->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		node = node->next;
	}
	write(1, "OK\n", 3);
}

static void	check_command(char *buf)
{
	if (ft_strcmp(buf, "pa") && ft_strcmp(buf, "pb")
		&& ft_strcmp(buf, "ra") && ft_strcmp(buf, "rb")
		&& ft_strcmp(buf, "rra") && ft_strcmp(buf, "rrb")
		&& ft_strcmp(buf, "rr") && ft_strcmp(buf, "rrr")
		&& ft_strcmp(buf, "sa") && ft_strcmp(buf, "sb")
		&& ft_strcmp(buf, "ss"))
		print_error(1);
}

static void	read_input(t_info *info)
{
	int		i;
	char	c;
	char	buf[4];

	i = 0;
	while (read(0, &c, 1))
	{
		if (c != '\n')
		{
			buf[i] = c;
			i++;
		}
		else
		{
			buf[i] = '\0';
			check_command(buf);
			operation(info, buf, 1);
			i = 0;
		}
		if (i > 3)
			print_error(1);
	}
}

static void	check_argv(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				flag = 1;
			j++;
		}
		if (flag == 0)
			print_error(1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arr;
	t_info	*info;

	if (argc < 2)
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		print_error(2);
	init_info(info);
	check_argv(argv);
	fill_stack(info, argv);
	check_overlap(info);
	read_input(info);
	check_sort(info->a_top);
	free_all(info);
}
