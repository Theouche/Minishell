/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:36 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/23 18:41:46 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_choose_type(va_list args, char c)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar_fd2(va_arg(args, int), 1);
	if (c == 's')
		p += ft_putstr_fd2(va_arg(args, char *), 1);
	if (c == 'p')
		p += ft_putpoint((unsigned long)va_arg(args, unsigned long));
	if (c == 'i' || c == 'd')
		p += ft_putnbr_fd2(va_arg(args, int), 1);
	if (c == 'u')
		p += ft_putnbr_un(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		p += ft_putnbrhexam(va_arg(args, unsigned int), c);
	if (c == '%')
		p += ft_putchar_pourcent();
	return (p);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		p;

	va_start(args, str);
	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			p += ft_choose_type(args, str[i + 1]);
			i++;
		}
		else
			p += ft_putchar_fd2(str[i], 1);
		i++;
	}
	va_end(args);
	return (p);
}
