/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:36:25 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/07 14:26:23 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == 0)
		return (NULL);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + j] = 0;
	return (str);
}
