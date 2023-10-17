/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:52:48 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/13 15:52:52 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] && str[i] != 34)
				i++;
			if (str[i] == 0)
				return (0);
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
				i++;
			if (str[i] == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_quote(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup_ms(char *src, int n)
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

size_t	ft_count_word_ms(char *str, char c)
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

void	ft_free_split(char **tab)
{
	int	i;

	if (!tab)
		ft_printf("------- NOT TAB\n");
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
