/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divers_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:51:02 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/23 19:01:57 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrhexam(unsigned int n, char c)
{
	int	p;

	if (!n)
		return (ft_putchar_fd2('0', 1));
	p = 0;
	if (n >= 16)
	{
		p += ft_putnbrhexam(n / 16, c);
		p += ft_putnbrhexam(n % 16, c);
	}
	else
	{
		if (n <= 9)
			p += ft_putchar_fd2(n + '0', 1);
		else
		{
			if (c == 'x')
				p += ft_putchar_fd2(n - 10 + 'a', 1);
			if (c == 'X')
				p += ft_putchar_fd2(n - 10 + 'A', 1);
		}
	}
	return (p);
}

int	ft_putchar_pourcent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putpoint(unsigned long n)
{
	int	p;

	p = 0;
	if (!n)
	{
		p += ft_putstr_fd2("(nil)", 1);
		return (p);
	}
	p += ft_putstr_fd2("0x", 1);
	p += ft_putnbrhexampo(n);
	return (p);
}

int	ft_putnbrhexampo(unsigned long n)
{
	int	p;

	p = 0;
	if (n >= 16)
	{
		p += ft_putnbrhexampo(n / 16);
		p += ft_putnbrhexampo(n % 16);
	}
	else
	{
		if (n <= 9)
			p += ft_putchar_fd2(n + '0', 1);
		else
			p += ft_putchar_fd2(n - 10 + 'a', 1);
	}
	return (p);
}

int	ft_putnbr_un(unsigned int n)
{
	int	p;

	p = 0;
	if (n > 9)
		p += ft_putnbr_un(n / 10);
	p += ft_putchar_fd2((n % 10) + '0', 1);
	return (p);
}
