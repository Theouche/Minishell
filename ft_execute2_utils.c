/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute2_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:45:07 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/13 16:45:09 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*good_path(char **split, char *test, char *cmd)
{
	char	*path;

	path = ft_strjoin(test, "/");
	path = ft_strjoin_and_free2(path, cmd);
	ft_free_split(split);
	return (path);
}

int	test_path(char *test, char *cmd)
{
	char	*path;

	path = ft_strjoin(test, "/");
	path = ft_strjoin_and_free2(path, cmd);
	if (access(path, X_OK) == 0)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

char	*recupthepath_2(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (cmd);
	else
		return (NULL);
}

char	*recupthepath(t_data *data, char *cmd)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	j = -1;
	if (cmd[0] == '/')
		return (recupthepath_2(cmd));
	while (data->cpyenv[++i])
	{
		if (ft_strncmp(data->cpyenv[i], "PATH", 4) == 0)
		{
			split = ft_split(data->path, ':');
			while (split[++j])
			{
				if (test_path(split[j], cmd) == 1)
					return (good_path(split, split[j], cmd));
			}
			ft_free_split(split);
		}
	}
	return (NULL);
}
