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

char	*special_case_3(int	shlvl)
{
	char	*new_shlvl;
	char	*num;

	num = ft_itoa(shlvl);
	new_shlvl = ft_strdup("SHLVL=");
	new_shlvl = ft_strjoin_and_free(new_shlvl, num);
	return (new_shlvl);
}

char	*special_case_2(char *shlvl)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char) * ft_strlen(shlvl));
	i = 0;
	while (shlvl[i + 6])
	{
		temp[i] = shlvl[i + 6];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

void	special_case_1(t_data *data, char **split)
{
	int		i;
	int		shlvl;
	char	*temp;
	char	*new_shlvl;

	if (split[1])
		ft_printf("Error, incorrect command\n");
	else
	{
		shlvl = 1;
		i = 0;
		while (data->cpyenv[i] && strncmp(data->cpyenv[i], "SHLVL", 5) != 0)
			i++;
		if (data->cpyenv[i] && strncmp(data->cpyenv[i], "SHLVL", 5) == 0)
		{
			temp = special_case_2(data->cpyenv[i]);
			shlvl += ft_atoi(temp);
			free(temp);
		}
		new_shlvl = special_case_3(shlvl);
		do_export(data, new_shlvl);
		free(new_shlvl);
	}
}

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
				path = ft_strjoin_and_free2(path, cmd);
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
	{
		execve(path, cmd, data->cpyenv);
		//printf("ok\n");
		//free(path);
	}
	else if (pid > 0)
	{
		waitpid(pid, &data->status, 0);
		//printf("ok\n");
		free(path);
		return ;
	}
	else
	{
		perror("fork could not get created :(");
		exit (1);
	}
	//free(path);
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
