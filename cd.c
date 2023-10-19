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
	char	*new_pwd;
	char	*new_cd;
	int		i;
	int		j;

	new_cd = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", new_cd);
	i = 0;
	j = 0;
	while (ft_strncmp(data->cpyenv[i], "PWD", 3) != 0)
		i++;
	while (ft_strncmp(data->cpyenv[j], "OLDPWD", 6) != 0)
		j++;
	free(data->cpyenv[i]);
	free(data->cpyenv[j]);
	data->cpyenv[i] = ft_strdup(new_pwd);
	data->cpyenv[j] = ft_strdup(old_pwd);
	free(new_cd);
	free(new_pwd);
}

int	apply_cd(t_data *data, char **dir)
{
	char	*old_pwd;
	char	*old_cd;

	old_cd = getcwd(NULL, 0);
	old_pwd = ft_strjoin("OLDPWD=", old_cd);
	data->status = 0;
	if (!dir[1] || (dir[1][0] == '~' && dir[1][1] == '\0'))
		chdir(data->home);
	else if (dir[2])
	{
		data->status = 1;
		ft_printf("cd: too many arguments\n");
	}
	else if (chdir(dir[1]) == -1)
	{
		data->status = 1;
		ft_printf("cd: no such file or directory: %s\n", dir[1]);
	}
	change_pwd_env(data, old_pwd);
	ft_free_split(dir);
	free(old_cd);
	free(old_pwd);
	return (3);
}
