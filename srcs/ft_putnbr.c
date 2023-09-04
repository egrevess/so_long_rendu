/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:44:50 by egrevess          #+#    #+#             */
/*   Updated: 2022/10/18 14:20:07 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nb, int *size, unsigned int base, char c)
{
	unsigned long	temp;

	temp = 0;
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, size, base, c);
		nb = nb % base;
	}
	if (nb < base)
	{
		if (nb < 10)
		{
			temp = nb + 48;
			write (1, &temp, 1);
			(*size)++;
		}
		else if (c != '\0')
		{
			temp = nb + c - 10;
			write(1, &temp, 1);
			(*size)++;
		}
	}
}

void	ft_putnbr(int nb, int *size)
{
	int	temp;

	temp = 0;
	if (nb == -2147483648)
		ft_putstr("-2147483648", size);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-', size);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10, size);
			nb = nb % 10;
		}
		if (nb < 10)
		{
			temp = nb + 48;
			ft_putchar (temp, size);
		}
	}
}
