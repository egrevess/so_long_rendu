/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:30 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/04 14:05:48 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include "get_next_line.h"

void	ft_putstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_error(void)
{
	ft_putstring("Error\n");
	exit (EXIT_FAILURE);
}

void	ft_init_tab(t_vars *var)
{
	var->len_col = nb_betweeen_nl(var->src);
	var->len_row = nb_nl(var->src);
	var->tab = make_tab(var);
	var->compt = 0;
	var->tab_check = make_tab(var);
	ft_free(&var->src, 0);
	check_map(var);
	ft_init_position(var);
	var->mlx = mlx_init();
	if (!var->mlx)
		exit(EXIT_FAILURE);
	var->win = mlx_new_window(var->mlx, 50 * var->len_col,
			50 * var->len_row, "so_long");
	if (!var->win)
		exit(EXIT_FAILURE);
	var->img = mlx_new_image(var->mlx, 50 * var->len_col,
			50 * var->len_row);
	if (!var->img)
		exit(EXIT_FAILURE);
	ft_init_mlx(var);
}

void	ft_print_compt(t_vars *var)
{
	++var->compt;
	ft_printf("%d\n", var->compt);
}
