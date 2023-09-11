/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:07:48 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/23 19:00:54 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd2(char c, int fd)
{
	int	p;

	p = 1;
	write(fd, &c, 1);
	return (p);
}

int	ft_putnbr_fd2(int n, int fd)
{
	int	p;

	p = 0;
	if (n == -2147483648)
	{
		p += write(fd, "-2147483648", 11);
		return (p);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			p += write(fd, "-", 1);
		}
		if (n > 9)
			p += ft_putnbr_fd2(n / 10, fd);
		p += ft_putchar_fd2((n % 10) + '0', fd);
	}
	return (p);
}

int	ft_putstr_fd2(char *s, int fd)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	if (!s)
	{
		p = ft_putstr_fd2("(null)", 1);
		return (p);
	}
	while (s[i])
	{
		p += ft_putchar_fd2(s[i], fd);
		i++;
	}
	return (p);
}
