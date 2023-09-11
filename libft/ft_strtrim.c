/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:06:30 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/07 11:25:47 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	deb;
	size_t	i;
	char	*str;

	len = ft_strlen(s1);
	if (ft_strlen(set) == 0 || len == 0)
		return (ft_strdup((char *)s1));
	deb = 0;
	while (s1[deb] && ft_strchr(set, s1[deb]))
		deb++;
	if (deb == len)
		return (ft_strdup(""));
	while (len > deb && ft_strchr(set, s1[len]))
		len--;
	str = malloc(sizeof(char) * (len - deb + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (deb <= len)
		str[i++] = s1[deb++];
	str[i] = 0;
	return (str);
}
