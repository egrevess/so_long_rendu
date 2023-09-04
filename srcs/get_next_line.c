/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:03:36 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/14 10:16:51 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_repere_ln(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_free(char **str, char **str2)
{
	if (str)
	{
		free(*str);
		*str = 0;
	}
	if (str2)
	{
		free(*str2);
		*str2 = 0;
	}
	return (NULL);
}

static char	*ft_return(char **temp, int read_ret)
{
	char	*line;

	if (ft_repere_ln(*temp) != -1)
	{
		line = strcpy_untill_nl(temp);
		if (line)
			*temp = strcpy_from_nl(*temp);
		return (line);
	}
	else if (read_ret <= 0 && !(*temp)[0])
		ft_free(temp, 0);
	else
	{
		line = ft_strdup(*temp);
		free(*temp);
		*temp = 0;
		return (line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int				read_ret;
	static char		*temp;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	buff = malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(&temp, NULL));
	read_ret = 1;
	buff[0] = '\0';
	while (ft_repere_ln(buff) == -1 && read_ret > 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		buff[read_ret * (read_ret >= 0)] = '\0';
		temp = ft_strcat(temp, &buff);
		if (!temp)
			return (0);
	}
	free(buff);
	return (ft_return(&temp, read_ret));
}
