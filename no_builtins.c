/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:10 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/11 15:01:28 by leudelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	no_builtin(t_data *data, char **env)
{
	char	*clean_cmd;
	
	(void)env;
	if (is_quote(data->fsplit[0]) == 1)
		clean_cmd = remove_quote(data->fsplit[0]);
	if (checkcmd(data->fsplit, data) == 1)
		return ;
	else
		return ;
}*/

void	no_env(t_data *data)
{
	char	*new_cd;
	char	*new_pwd;
	char	*old_pwd;

	new_cd = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", new_cd);
	data->cpyenv[0] = ft_strdup(new_pwd);
	old_pwd = ft_strjoin("OLDPWD=", new_cd);
	data->cpyenv[1] = ft_strdup(old_pwd);
	data->cpyenv[2] = ft_strdup("SHLVL=1");
	data->cpyenv[3] = 0;
	free(old_pwd);
	free(new_pwd);
}
