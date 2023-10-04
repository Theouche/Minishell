/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:52:30 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/04 14:25:42 by leudelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *data, char *cmd)
{
	char	**split;

	split = ft_split(cmd, ' ');
	//printf("la commamde est : %s\n", split[0]);
	if (ft_strcmp(split[0], "echo") == 0)
		return (apply_echo(cmd, data));
	else if (ft_strcmp(split[0], "cd") == 0)
		return (apply_cd(data, split));
	else if (ft_strcmp(split[0], "pwd") == 0)
		return (apply_pwd(data));
	else if (ft_strcmp(split[0], "env") == 0)
		return (apply_env(data));
	else if (ft_strcmp(split[0], "export") == 0)
		return (apply_export(data, split));
	else if (ft_strcmp(split[0], "unset") == 0)
		return (apply_unset(data, split));
	/*if (ft_strcmp(cmd, "exit") == 0)
		return (apply_exit(cmd));*/
	else
		return (0);
	//Penser a free le split --> necessiter de couper la fonction en 2 ?
}

void	execute_cmd(t_data *data, char *cmd)
{
	char	**split;
	/*int	i;

	i = 0;
	while (lst_cmd[i])
	{
		if (!is_builtin(lst_cmd[i], env))
			i++;
		i++;
	}*/
	if (!is_builtin(data, cmd))
	{
		split = ft_split(cmd, ' ');
		checkcmd(split, data);
		//ft_free_split(split);
		return ; //mettre ici la fonction pour les non-builtins.
	}
}

void	begin_cmd(t_data *data, char *cmd)
{
	/*if (data->num_pip == 0)
		execute_cmd(data, env);
	else
	{
		// pour si il y a des pipes !.
		return ;
	}*/
	/*int	i;

	i = 0;
	while (data->cmd[i])
	{
		//printf("la recherche vaut %d \n",ft_strchr_dbred(data->cmd[i], '>'));
		if (ft_strchr_dbred(data->cmd[i], '>') == 1)
			ft_redir_double_droite(data, data->cmd[i]);
		else if (ft_strchr_dbred(data->cmd[i], '<') == 1)
			ft_redir_double_gauche(data, data->cmd[i]);
		else if (ft_strchr_red(data->cmd[i], '>') == 1)
			ft_redir_droite(data, data->cmd[i]);
		else if (ft_strchr_red(data->cmd[i], '<') == 1)
			ft_redir_gauche(data, data->cmd[i]);
		else
		{
			if (i == 0 && data->num_pip >=1 )
				forpipe(data->cmd, data);
			execute_cmd(data, data->cmd[i]);
		}
		i++;
		printf("ok pour commande %d\n", i -1);
	}*/
	if (ft_strchr_dbred(cmd, '>') == 1)
		ft_redir_double_droite(data, cmd);
	else if (ft_strchr_dbred(cmd, '<') == 1)
		ft_redir_double_gauche(data, cmd);
	else if (ft_strchr_red(cmd, '>') == 1)
		ft_redir_droite(data, cmd);
	else if (ft_strchr_red(cmd, '<') == 1)
		ft_redir_gauche(data, cmd);
	else
		execute_cmd(data, cmd);
}
