/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:05:58 by egrevess          #+#    #+#             */
/*   Updated: 2022/12/08 10:34:29 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *size);
void	ft_putstr(char *str, int *size);
void	ft_put_addresshexa(void *s, int *size);
void	ft_putnbr_base(unsigned long s, int *size, unsigned int base, char c);
void	ft_putnbr(int nb, int *size);

#endif
