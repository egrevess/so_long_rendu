/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:08 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/11 11:20:04 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"

static void	put_what(t_vars *var, char **tab, t_vars map);

void	ft_init_mlx(t_vars *var)
{
	var->img_height = 50;
	var->img_width = 50;
	var->img_wall = mlx_xpm_file_to_image(var->mlx, "./srcs/mur_small.xpm",
			&var->img_width, &var->img_height);
	var->img_items = mlx_xpm_file_to_image(var->mlx, "./srcs/items_small.xpm",
			&var->img_width, &var->img_height);
	var->img_end = mlx_xpm_file_to_image(var->mlx, "./srcs/end_small.xpm",
			&var->img_width, &var->img_height);
	var->img_position = mlx_xpm_file_to_image(var->mlx,
			"./srcs/position_small.xpm", &var->img_width, &var->img_height);
	var->img_void = mlx_xpm_file_to_image(var->mlx, "./srcs/void_small.xpm",
			&var->img_width, &var->img_height);
	var->img_white = mlx_xpm_file_to_image(var->mlx, "./srcs/blanc.xpm",
			&var->img_width, &var->img_height);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	if (!var->img_wall || !var->img_items || !var->img_end || !var->img_position
		|| !var->img_void || !var->img_white || !var->addr)
		ft_error();
	put_what(var, var->tab, *var);
}

static void	put_img(t_vars *var, char tab, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img_white, x, y);
	if (tab == '1')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_wall, x, y);
	}
	if (tab == '0')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_void, x, y);
	}
	if (tab == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_items, x, y);
	}
	if (tab == 'E')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_end, x, y);
	}
	if (tab == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_position, x, y);
	}
}

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == KEY_UP)
	{
		if (var->tab[var->position_y_p - 1][var->position_x_p] != '1')
			ft_swap_up(var);
	}
	else if (keycode == KEY_LEFT)
	{
		if (var->tab[var->position_y_p][var->position_x_p - 1] != '1')
			ft_swap_left(var);
	}
	else if (keycode == KEY_DOWN)
	{
		if (var->tab[var->position_y_p + 1][var->position_x_p] != '1')
			ft_swap_down(var);
	}
	else if (keycode == KEY_RIGHT)
	{
		if (var->tab[var->position_y_p][var->position_x_p + 1] != '1')
			ft_swap_right(var);
	}
	else if (keycode == KEY_ESC)
		ft_close(var);
	return (0);
}

static void	put_what(t_vars *var, char **tab, t_vars map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < map.len_row)
	{
		j = 0;
		x = 0;
		while (j < map.len_col)
		{
			put_img(var, tab[i][j], x, y);
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
}

int	ft_close(t_vars *var)
{
	if (var->img_end)
		mlx_destroy_image(var->mlx, var->img_end);
	if (var->img_position)
		mlx_destroy_image(var->mlx, var->img_position);
	if (var->img_void)
		mlx_destroy_image(var->mlx, var->img_void);
	if (var->img_items)
		mlx_destroy_image(var->mlx, var->img_items);
	if (var->img_wall)
		mlx_destroy_image(var->mlx, var->img_wall);
	if (var->img)
	{
		mlx_destroy_image(var->mlx, var->img);
		var->img = NULL;
	}
	if (var->win)
	{
		mlx_destroy_window(var->mlx, var->win);
		var->mlx = NULL;
	}
	free_tab(var);
	free_tab_check(var);
	exit (EXIT_SUCCESS);
	return (0);
}
