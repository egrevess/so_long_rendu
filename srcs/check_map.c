/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:16:35 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/11 11:11:22 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib_so_long.h"

static void	check_wall(t_vars *var)
{
	int	check;
	int	j;

	check = 0;
	j = 0;
	while (j < var->len_col && check == 0)
	{
		if (var->tab[0][j] != '1' || var->tab[var->len_row - 1][j] != '1')
			check = 1;
		j++;
	}
	j = 0;
	while (j < var->len_row && check == 0)
	{
		if (var->tab[j][0] != '1' || var->tab[j][var->len_col - 1] != '1')
			check = 1;
		j++;
	}
	if (check == 1)
		ft_error();
}

static void	check_enter_end(t_vars *var)
{
	int	check_e;
	int	check_p;
	int	j;
	int	i;

	check_e = 0;
	check_p = 0;
	j = 1;
	i = 1;
	while (i < var->len_row - 1)
	{
		j = 1;
		while (j < var->len_col - 1)
		{
			if (var->tab[i][j] == 'E')
				check_e++;
			else if (var->tab[i][j] == 'P')
				check_p++;
			j++;
		}
		i++;
	}
	if (check_e != 1 || check_p != 1)
		ft_error();
}

static int	check_items(t_vars *var)
{
	int	check_i;
	int	j;
	int	i;

	check_i = 0;
	j = 1;
	i = 1;
	while (i < var->len_row - 1)
	{
		j = 1;
		while (j < var->len_col - 1)
		{
			if (var->tab[i][j] == 'C')
				check_i++;
			j++;
		}
		i++;
	}
	if (check_i < 1)
		ft_error();
	return (check_i);
}

int	check_win(t_vars *var)
{
	int	check_i;
	int	j;
	int	i;

	check_i = 0;
	j = 1;
	i = 1;
	while (i < var->len_row - 1)
	{
		j = 1;
		while (j < var->len_col - 1)
		{
			if (var->tab[i][j] == 'C' && (i != var->position_y_p
				|| j != var->position_x_p))
			{
				check_i = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (check_i);
}

void	check_map(t_vars *var)
{
	check_wall(var);
	check_enter_end(var);
	check_items(var);
	if (check_valid_path(var) != 0)
		ft_error();
	else if (check_exit(var) != 0)
		ft_error();
}
