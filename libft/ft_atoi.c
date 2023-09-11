/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:18:20 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/04 16:33:29 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	valeur;
	int	moins;

	i = 0;
	valeur = 0;
	moins = 1;
	while (str[i] && ((str[i] < 14 && str[i] > 8) || str[i] == 32))
		i++;
	if (str[i] == '-')
		moins *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		valeur = valeur * 10 + str[i] - '0';
		i++;
	}
	return (valeur * moins);
}
