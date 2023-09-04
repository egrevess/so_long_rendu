/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:16:31 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/14 10:16:32 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"

int	check_exit(t_vars *var)
{
	var->tab_check[var->posx][var->posy] = 'P';
	while (check_position(var) != 0)
	{
		if (var->tab_check[var->posx + 1][var->posy] == 'X'
			|| var->tab_check[var->posx + 1][var->posy] == 'E'
			|| var->tab_check[var->posx + 1][var->posy] == 'P')
			var->tab_check[var->posx + 1][var->posy] = 'P';
		if (var->tab_check[var->posx - 1][var->posy] == 'X'
			|| var->tab_check[var->posx - 1][var->posy] == 'E'
			|| var->tab_check[var->posx - 1][var->posy] == 'P')
			var->tab_check[var->posx - 1][var->posy] = 'P';
		if (var->tab_check[var->posx][var->posy + 1] == 'X'
			|| var->tab_check[var->posx][var->posy + 1] == 'E'
			|| var->tab_check[var->posx][var->posy + 1] == 'P')
			var->tab_check[var->posx][var->posy + 1] = 'P';
		if (var->tab_check[var->posx][var->posy - 1] == 'X'
			|| var->tab_check[var->posx][var->posy - 1] == 'E'
			|| var->tab_check[var->posx][var->posy - 1] == 'X')
			var->tab_check[var->posx][var->posy - 1] = 'P';
		var->tab_check[var->posx][var->posy] = '0';
		if (check_position(var) == 0)
			break ;
		ft_init_position_check(var);
	}
	return (check_enter(var));
}
