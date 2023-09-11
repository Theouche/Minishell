/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:26:40 by tlorne            #+#    #+#             */
/*   Updated: 2023/08/05 15:21:05 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_getenv(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->cpyenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		data->cpyenv[i] = ft_strdup(env[i]);
		i++;
	}

}

void	ft_getpath(t_data *data)
{
	int	i;

	i = 0;
	while (strncmp(data->cpyenv[i], "PATH", 4) != 0)
		i++;
	data->path = ft_strdup(data->cpyenv[i]);
}

void	ft_gethome(t_data *data)
{
	int	i;

	i = 0;
	while (strncmp(data->cpyenv[i], "HOME", 4) != 0)
		i++;
	data->home = ft_strdup(data->cpyenv[i]);
}

void	ft_getpwd(t_data *data)
{
	int	i;

	i = 0;
	while (strncmp(data->cpyenv[i], "PWD", 3) != 0)
		i++;
	data->pwd = ft_strdup(data->cpyenv[i]);
}

void	ft_init(t_data *data, char **env)
{
	ft_getenv(data, env);
	ft_getpwd(data);
	ft_gethome(data);
	ft_getpath(data);
}
