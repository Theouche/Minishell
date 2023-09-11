/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:27:03 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/10 15:11:19 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long_int(int c)
{
	int	len;

	len = 0;
	if (c < 0)
		len++;
	while (c != 0)
	{
		len++;
		c = c / 10;
	}
	return (len);
}

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	if (n == 0)
		return (ft_zero());
	len = ft_long_int(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else
		num = n;
	str[len] = '\0';
	while (num != 0)
	{
		str[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
