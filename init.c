/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:26:40 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/12 12:47:46 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_getenv(t_data *data, char **env)
{
	int	i;

	i = 0;
	if (!env[0])
	{
		data->cpyenv = malloc(sizeof(char *) * 4);
		no_env(data);
		return ;
	}
	while (env[i])
		i++;
	data->cpyenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		data->cpyenv[i] = ft_strdup(env[i]);
		i++;
	}
	data->cpyenv[i] = 0;
}

void	ft_getpath(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (data->cpyenv[i] && strncmp(data->cpyenv[i], "PATH", 4) != 0)
		i++;
	//data->path = ft_strdup(data->cpyenv[i]);
	if (data->cpyenv[i] && strncmp(data->cpyenv[i], "PATH", 4) == 0)
	{
		data->path = malloc(sizeof(char) * (ft_strlen(data->cpyenv[i]) + 1));
		k = 0;
		j = 5;
		while (data->cpyenv[i][j])
		{
			data->path[k] = data->cpyenv[i][j];
			k++;
			j++;
		}
		data->path[k] = 0;
	}
	//printf("Path vaut : %s\n", data->path);
}

void	ft_gethome(t_data *data)
{
	int	i;

	i = 0;
	while (data->cpyenv[i] && strncmp(data->cpyenv[i], "HOME", 4) != 0)
		i++;
	if (data->cpyenv[i] && strncmp(data->cpyenv[i], "HOME", 4) == 0)
		data->home = ft_strdup(data->cpyenv[i]);
	else
		return ;
}

void	ft_getpwd(t_data *data)
{
	int	i;

	i = 0;
	while (strncmp(data->cpyenv[i], "PWD", 3) != 0)
		i++;
	if (data->cpyenv[i] && strncmp(data->cpyenv[i], "PWD", 3) == 0)
		data->pwd = ft_strdup(data->cpyenv[i]);
	else
		return ;
}

void	ft_init(t_data *data, char **env)
{
	ft_getenv(data, env);
	ft_getpwd(data);
	ft_gethome(data);
	ft_getpath(data);
}
