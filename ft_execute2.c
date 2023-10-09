/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leudelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:45:59 by leudelin          #+#    #+#             */
/*   Updated: 2023/10/07 16:03:27 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

char	*recupthepath(t_data *data, char *cmd)
{
	char	*path;
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
			while (split[j])
			{
				path = ft_strjoin(split[j], "/");
				path = ft_strjoin(path, cmd);
				if (access(path, X_OK) == 0)
				{
					ft_free_split(split);
					return (path);
				}
				free(path);
				j++;
			}
			ft_free_split(split);
		}
		i++;
	}
	return (NULL);
}

void	checkcmd(char **cmd, t_data *data)
{
	char	*path;
	pid_t	pid;

	path = recupthepath(data, cmd[0]);
	pid = fork();
	if (pid == 0)
		execve(path, cmd, data->cpyenv);
	else if (pid > 0)
	{
		waitpid(pid, &data->status, 0);
		return ;
	}
	else
	{
		perror("fork could not get created :(");
		exit (1);
	}
	exit(127);
}

int	exitstatus(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (status);
}
