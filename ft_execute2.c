/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leudelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:45:59 by leudelin          #+#    #+#             */
/*   Updated: 2023/10/02 10:28:15 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

char	*recupthepath(t_data *data, char *cmd)
{
	char	*path;
//	char	*path2;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	while (data->cpyenv[i])
	{
		if (ft_strncmp(data->cpyenv[i], "PATH", 4) == 0)
		{
			split = ft_split(data->path, ':');
			//j = 0;
			while (split[j])
			{
				path = ft_strjoin(split[j], "/");
				path = ft_strjoin(path, cmd);
				//printf("path est %s\n", path);
				if (access(path, X_OK) == 0)
				{
					//free(path1);
					ft_free_split(split);
					return (path);
				}
				free(path);
				//free(path2);
				j++;
			}
			ft_free_split(split);
			//path = "/usr/bin/";
			//path = ft_strjoin(path, *data->cmd); //il faudra surement free sa a un moment
			//return(path);
		}
		i++;
	}
	return (NULL);
}

void	checkcmd(char **cmd, t_data *data)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = recupthepath(data, cmd[0]);
	//printf("le path vaur %s\n", path);
	pid = fork();
	if (pid == 0)
		execve(path, cmd, data->cpyenv);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return ;
	}
	else
	{
		perror("fork could not get created :(");
		exit (1);
	}
}