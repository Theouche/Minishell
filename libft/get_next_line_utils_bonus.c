/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:40:00 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/23 18:57:39 by tlorne           ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = (char *) s;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}
