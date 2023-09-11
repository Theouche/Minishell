/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:59:05 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 19:53:14 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	i = 0;
	ls = 0;
	ld = 0;
	while (src[ls] != '\0')
		ls++;
	if (size == 0)
		return (ls);
	while (dst[ld] != '\0' && ld < size)
		ld++;
	while (src[i] != '\0' && ld + i < size - 1 && size > 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	if (ld + i < size)
		dst[ld + i] = '\0';
	return (ls + ld);
}
