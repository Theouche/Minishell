/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:01:13 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 18:07:14 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*bufdest;
	char	*bufsrc;

	if (!src && !dest && n)
		return (NULL);
	i = 0;
	bufdest = (char *) dest;
	bufsrc = (char *) src;
	if (dest > src)
	{
		while (n-- > 0)
			bufdest[n] = bufsrc[n];
		return (dest);
	}
	while (i < n)
	{
		bufdest[i] = bufsrc[i];
		i++;
	}
	return (dest);
}
