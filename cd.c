/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:41:31 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/04 18:11:18 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd_env(t_data *data, char *old_pwd)
{
	/*int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_strncmp(env[i], "PWD", 3))
		i++;
	while (!ft_strncmp(data->cpyenv[j], "PWD", 3))
		j++;
	data->cpyenv[j] = ft_strdup(env[i]);
	i = 0;
	j = 0;
	while (!ft_strncmp(env[i], "OLDPWD", 6))
		i++;
	while (!ft_strncmp(data->cpyenv[j], "OLDPWD", 6))
		j++;
	data->cpyenv[j] = ft_strdup(env[i]);*/

	// new version 

	char	*new_pwd;
	int		i;
	int		j;

	new_pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
	i = 0;
	j = 0;
	while (ft_strncmp(data->cpyenv[i], "PWD", 3) != 0)
		i++;
	while (ft_strncmp(data->cpyenv[j], "OLDPWD", 6) != 0)
		j++;
	data->cpyenv[i] = ft_strdup(new_pwd);
	data->cpyenv[j] = ft_strdup(old_pwd);
}

int	apply_cd(t_data *data, char **env)
{
	char	**dir;
	char	*old_pwd;

	(void)env;
	dir = ft_split(data->fsplit[0], ' ');
	old_pwd = ft_strjoin("OLDPWD=", getcwd(NULL, 0));;
	if (!dir[1] || (dir[1][0] == '~' && dir[1][1] == '\0'))
		chdir(data->home);
	else if (dir[2])
		ft_printf("cd: too many arguments\n");
	else if (chdir(dir[1]) == -1)
		ft_printf("cd: no such file or directory: %s\n", dir[1]);
	change_pwd_env(data, old_pwd);
	ft_free_split(dir);
	return (3);
}
