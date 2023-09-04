/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:51 by egrevess          #+#    #+#             */
/*   Updated: 2022/10/18 13:30:07 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *size)
{
	write (1, &c, 1);
	(*size)++;
}

void	ft_putstr(char	*str, int *size)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write (1, &str[i], 1);
		(*size)++;
		i++;
	}
}

void	ft_put_addresshexa(void *s, int *size)
{
	ft_putstr("0x", size);
	ft_putnbr_base((unsigned long) s, size, 16, 'a');
}
