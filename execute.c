/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:52:30 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/12 14:44:39 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *data, char **env)
{
	printf("la commamde est : %s\n", data->cmd[0]);
	if (ft_strcmp(data->cmd[0], "echo") == 0)
		return (apply_echo(data));
	if (ft_strcmp(data->cmd[0], "cd") == 0)
		return (apply_cd(data, env));
	if (ft_strcmp(data->cmd[0], "pwd") == 0)
		return (apply_pwd(data, env));
	if (ft_strcmp(data->cmd[0], "env") == 0)
		return (apply_env(data, env));
	if (ft_strcmp(data->cmd[0], "export") == 0)
		return (apply_export(data));
	if (ft_strcmp(data->cmd[0], "unset") == 0)
		return (apply_unset(data));
	/*if (ft_strcmp(cmd, "exit") == 0)
		return (apply_exit(cmd));*/
	else
		return (0);
}

void	execute_cmd(t_data *data, char **env)
{
	/*int	i;

	i = 0;
	while (lst_cmd[i])
	{
		if (!is_builtin(lst_cmd[i], env))
			i++;
		i++;
	}*/
	if (!is_builtin(data, env))
	{
		no_builtins(data, env);
		return ; //mettre ici la fonction pour les non-builtins.
	}
}

void	begin_cmd(t_data *data, char **env)
{
	if (data->num_pip == 0)
		execute_cmd(data, env);
	else
	{
		// pour si il y a des pipes !.
		return ;
	}
		
}
