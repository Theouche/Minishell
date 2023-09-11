/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:19:36 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/06 14:50:44 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff1;
	unsigned char	*buff2;

	buff1 = (unsigned char *) s1;
	buff2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (buff1[i] != buff2[i])
			return ((int)(buff1[i] - buff2[i]));
		i++;
	}
	return (0);
}
