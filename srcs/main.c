/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:16:20 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/11 11:08:51 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_perror(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

static t_vars	*get_map(t_vars *var, char *av)
{
	int		fd;
	int		i;
	char	*line;

	var->src = malloc(sizeof(char *) * 1);
	if (!var->src)
		return ((void *) ft_free(&var->src, 0));
	var->src[0] = '\0';
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_perror(__func__);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_len(line, i);
		var->src = f_strcat(var->src, &line);
		ft_free(&line, 0);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (!i || var->src[f_strlen(var->src) - 1] == '\n')
		ft_error();
	return (var);
}

static int	check_ber(char *av)
{
	int	len;

	len = ft_strlen(av) - 1;
	if (av[len] == 'r' && av[len - 1] == 'e'
		&& av[len - 2] == 'b' && av[len - 3] == '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars		var;

	if (ac != 2)
		return (1);
	if (check_ber(av[1]) == 1)
		return (1);
	var.src = NULL;
	get_map(&var, av[1]);
	if (var.src == NULL || !var.src[0])
		return (1);
	ft_init_tab(&var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, ft_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
