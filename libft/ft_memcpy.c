/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:44:13 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 17:30:56 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*buffer1;
	char	*buffer2;

	if (!n || dest == src)
		return (dest);
	i = 0;
	buffer1 = (char *) dest;
	buffer2 = (char *) src;
	while (i < n)
	{
		buffer1[i] = buffer2[i];
		i++;
	}
	return (dest);
}
