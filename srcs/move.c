/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:26 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/04 14:06:24 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include "get_next_line.h"

void	ft_init_position(t_vars *var)
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
			if (var->tab[i][j] == 'P')
			{
				check = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	var->position_x_p = j;
	var->position_y_p = i - 1;
}

void	ft_swap_up(t_vars *var)
{
	if (var->tab[var->position_y_p - 1][var->position_x_p] == 'E'
		&& check_win(var) == 0)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			var->position_x_p * 50, (var->position_y_p * 50) - 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->position_y_p = var->position_y_p - 1;
		ft_print_compt(var);
		ft_close(var);
	}
	else if (var->tab[var->position_y_p - 1][var->position_x_p] != 'E')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			var->position_x_p * 50, (var->position_y_p * 50) - 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->tab[var->position_y_p][var->position_x_p] = '0';
		var->position_y_p = var->position_y_p - 1;
		ft_print_compt(var);
	}
}

void	ft_swap_down(t_vars *var)
{
	if (var->tab[var->position_y_p + 1][var->position_x_p] == 'E'
		&& check_win(var) == 0)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			var->position_x_p * 50, (var->position_y_p * 50) + 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->position_y_p = var->position_y_p + 1;
		ft_print_compt(var);
		ft_close(var);
	}
	else if (var->tab[var->position_y_p + 1][var->position_x_p] != 'E')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			var->position_x_p * 50, (var->position_y_p * 50) + 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->tab[var->position_y_p][var->position_x_p] = '0';
		var->position_y_p = var->position_y_p + 1;
		ft_print_compt(var);
	}
}

void	ft_swap_left(t_vars *var)
{
	if (var->tab[var->position_y_p][var->position_x_p - 1] == 'E'
		&& check_win(var) == 0)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			(var->position_x_p * 50) - 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->position_x_p = var->position_x_p - 1;
		ft_print_compt(var);
		ft_close(var);
	}
	else if (var->tab[var->position_y_p][var->position_x_p - 1] != 'E')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			(var->position_x_p * 50) - 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->tab[var->position_y_p][var->position_x_p] = '0';
		var->position_x_p = var->position_x_p - 1;
		ft_print_compt(var);
	}
}

void	ft_swap_right(t_vars *var)
{
	if (var->tab[var->position_y_p][var->position_x_p + 1] == 'E'
		&& check_win(var) == 0)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			(var->position_x_p * 50) + 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->position_x_p = var->position_x_p + 1;
		ft_print_compt(var);
		ft_close(var);
	}
	else if (var->tab[var->position_y_p][var->position_x_p + 1] != 'E')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position,
			(var->position_x_p * 50) + 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_white,
			var->position_x_p * 50, var->position_y_p * 50);
		mlx_put_image_to_window(var->mlx, var->win, var->img_void,
			var->position_x_p * 50, var->position_y_p * 50);
		var->tab[var->position_y_p][var->position_x_p] = '0';
		var->position_x_p = var->position_x_p + 1;
		ft_print_compt(var);
	}
}
