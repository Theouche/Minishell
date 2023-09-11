/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:51:27 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/10 15:15:07 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static size_t	ft_count_word(const char *str, char c)
{
	int		i;
	size_t	count;
	int		block;

	count = 0;
	block = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && block == 0)
		{
			block = 1;
			count++;
		}
		else if (str[i] == c)
			block = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		pos;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		pos = i;
		while (s[i] != c && s[i])
			i++;
		if (pos != i)
		{
			tab[j] = ft_strndup(s + pos, i - pos);
			j++;
		}
		if (s[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}
