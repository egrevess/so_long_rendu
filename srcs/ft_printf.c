/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:24:45 by egrevess          #+#    #+#             */
/*   Updated: 2022/11/10 13:14:56 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_what(char c, va_list ptr, int *size)
{
	if (c == 'c')
		ft_putchar(va_arg(ptr, int), size);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ptr, int), size);
	else if (c == 's')
		ft_putstr(va_arg(ptr, char *), size);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ptr, unsigned int), size, 16, 'a');
	else if (c == 'X')
		ft_putnbr_base(va_arg(ptr, unsigned int), size, 16, 'A');
	else if (c == 'u')
		ft_putnbr_base(va_arg(ptr, unsigned int), size, 10, '\0');
	else if (c == 'p')
		ft_put_addresshexa(va_arg(ptr, void *), size);
	else if (c == '%')
		ft_putchar (c, size);
}

static void	ft_putchar_format(char format)
{
	write(1, &format, 1);
}

static int	ft_char_conv(char c)
{
	int		i;
	char	*src;

	src = "cspdiuxX";
	i = 0;
	while (src[i])
	{
		if (c == src[i])
			return (1);
		i++;
	}
	if (c == '%')
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		size;
	int		i;

	i = 0;
	size = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && (ft_char_conv(format[i + 1]) == 1
				|| ft_char_conv(format[i + 1]) == -1))
			ft_what(format[(i++) + 1], ptr, &size);
		else if (format[i] == '%' && ft_char_conv(format[i + 1]) != 1
			&& ft_char_conv(format[i + 1]) != -1)
			break ;
		else if (format[i] != '%')
		{
			ft_putchar_format(format[i]);
			size++;
		}
		i++;
	}
	va_end(ptr);
	return (size);
}
