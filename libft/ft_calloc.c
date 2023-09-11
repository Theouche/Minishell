/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:07:43 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 18:25:42 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	temp;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	temp = nmemb * size;
	if (nmemb != temp / size)
		return (NULL);
	ptr = malloc(temp);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, temp);
	return ((void *)ptr);
}
