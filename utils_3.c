/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:07 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/13 16:13:09 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

char	*ft_remove_first_space(char *cmd)
{
	char	*dup;
	int		i;
	int		deb;

	i = 0;
	deb = 0;
	while (cmd[i] == ' ' || cmd[i] == '\t')
		i++;
	dup = malloc(ft_strlen(cmd) - i + 1 * sizeof(char));
	while (cmd[i])
		dup[deb++] = cmd[i++];
	dup[deb] = 0;
	return (dup);
}

char	*first_word(char *cmd)
{
	int		i;
	char	*fw;

	i = 0;
	fw = malloc(sizeof(char) * 7);
	while (ft_isalpha(cmd[i]))
	{
		fw[i] = cmd[i];
		i++;
	}
	fw[i] = 0;
	return (fw);
}
