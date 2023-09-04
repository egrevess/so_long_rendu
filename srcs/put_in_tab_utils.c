/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab_outils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:34 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/04 13:55:29 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"

int	nb_nl(char *src)
{
	int	nl;
	int	i;

	nl = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			nl++;
		i++;
	}
	return (nl + 1);
}

int	nb_betweeen_nl(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	return (i);
}

char	**put_in_tab(char **res, t_vars *var)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (i < var->len_row)
	{
		j = 0;
		while (j < var->len_col)
		{
			res[i][j] = var->src[index];
			j++;
			index++;
		}
		res[i][j] = '\0';
		index++;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*free_tab(t_vars *var)
{
	int	i;

	i = 0;
	while (i < var->len_row)
	{
		free(var->tab[i]);
		i++;
	}
	free(var->tab);
	return (NULL);
}

char	*free_tab_check(t_vars *var)
{
	int	i;

	i = 0;
	while (i < var->len_row)
	{
		free(var->tab_check[i]);
		i++;
	}
	free(var->tab_check);
	return (NULL);
}
