/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:16:38 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/11 11:14:03 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib_so_long.h"

int	check_enter(t_vars *var)
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
			if (var->tab_check[i][j] == 'E')
				check_i = 1;
			j++;
		}
		i++;
	}
	return (check_i);
}

int	check_position(t_vars *var)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 1;
	while (i < var->len_row - 1 && check == 0)
	{
		j = 1;
		while (j < var->len_col - 1)
		{
			if (var->tab_check[i][j] == 'P')
			{
				check = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (check);
}

static int	check_items_check(t_vars *var)
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
			if (var->tab_check[i][j] == 'C')
				check_i++;
			j++;
		}
		i++;
	}
	return (check_i);
}

void	ft_init_position_check(t_vars *var)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 1;
	while (i < var->len_row - 1 && check == 0)
	{
		j = 1;
		while (j < var->len_col - 1)
		{
			if (var->tab_check[i][j] == 'P')
			{
				check = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	var->posy = j;
	var->posx = i - 1;
}

int	check_valid_path(t_vars *var)
{
	ft_init_position_check(var);
	while (check_position(var) != 0 || check_items_check(var) != 0)
	{
		if ((var->tab_check[var->posx + 1][var->posy] == '0'
			|| var->tab_check[var->posx + 1][var->posy] == 'C'
			|| var->tab_check[var->posx + 1][var->posy] == 'P'))
			var->tab_check[var->posx + 1][var->posy] = 'P';
		if ((var->tab_check[var->posx - 1][var->posy] == '0'
			|| var->tab_check[var->posx - 1][var->posy] == 'C'
			|| var->tab_check[var->posx - 1][var->posy] == 'P'))
			var->tab_check[var->posx - 1][var->posy] = 'P';
		if ((var->tab_check[var->posx][var->posy + 1] == '0'
			|| var->tab_check[var->posx][var->posy + 1] == 'C'
			|| var->tab_check[var->posx][var->posy + 1] == 'P'))
			var->tab_check[var->posx][var->posy + 1] = 'P';
		if ((var->tab_check[var->posx][var->posy - 1] == '0'
			|| var->tab_check[var->posx][var->posy - 1] == 'C'
			|| var->tab_check[var->posx][var->posy - 1] == 'P'))
			var->tab_check[var->posx][var->posy - 1] = 'P';
		var->tab_check[var->posx][var->posy] = 'X';
		if (check_position(var) == 0)
			break ;
		ft_init_position_check(var);
	}
	return (check_items_check(var));
}
