/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:22 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/04 13:55:45 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include "get_next_line.h"

void	check_len(char *line, int i)
{
	static int	len;
	int			temp;

	temp = f_strlen(line);
	if (ft_repere_ln(line) == -1)
		temp = temp + 1;
	if (i == 0)
		len = temp;
	else if (len != temp)
	{
		ft_putstring("Error\n");
		exit (EXIT_FAILURE);
	}
}

char	*f_strcat(char *src, char **line)
{
	char	*res;
	int		line_len;
	int		src_len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	line_len = ft_strlen(*line);
	src_len = ft_strlen(src);
	res = malloc(sizeof(*res) * (line_len + src_len + 1));
	if (!res)
		return (ft_free(0, line));
	while (++i < src_len)
		res[i] = src[i];
	ft_free(&src, 0);
	while (j < line_len)
	{
		res[i + j] = (*line)[j];
		j++;
	}	
	res[i + j] = '\0';
	return (res);
}

char	**make_tab(t_vars *var)
{
	char	**res;
	int		i;
	int		index;

	res = malloc(sizeof(char *) * (var->len_row + 1));
	if (!res)
		ft_perror(__func__);
	i = 0;
	while (i < var->len_row)
	{
		res[i] = malloc(sizeof(char) * (var->len_col + 1));
		if (!res[i])
		{
			index = i;
			while (index >= 0)
			{
				free(res[index]);
				index--;
			}
			free(res);
			ft_perror(__func__);
		}
		i++;
	}
	return (put_in_tab(res, var));
}
