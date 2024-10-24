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

int	is_builtin_2(char **split, t_data *data)
{
	if (ft_strcmp(split[0], "export") == 0)
		return (apply_export(data, split));
	else if (ft_strcmp(split[0], "unset") == 0)
		return (apply_unset(data, split));
	else if (ft_strcmp(split[0], "cd") == 0)
		return (apply_cd(data, split));
	else
	{
		ft_free_split(split);
		return (0);
	}
}

int	is_builtin(t_data *data, char *cmd)
{
	char	**split;

	split = ft_split(cmd, ' ');
	if (ft_strcmp(split[0], "echo") == 0)
	{
		ft_free_split(split);
		data->status = 0;
		return (apply_echo(cmd, data));
	}
	else if (ft_strcmp(split[0], "pwd") == 0)
	{
		ft_free_split(split);
		return (apply_pwd(data));
	}
	else if (ft_strcmp(split[0], "env") == 0)
	{
		ft_free_split(split);
		return (apply_env(data));
	}
	else
		return (is_builtin_2(split, data));
}

void	execute_cmd(t_data *data, char *cmd)
{
	char	**split;
	char	*cmd_2;

	if (!is_builtin(data, cmd))
	{
		if (is_quote(cmd))
			cmd_2 = remove_quote(cmd);
		else
			cmd_2 = ft_strdup(cmd);
		split = ft_split(cmd_2, ' ');
		if (ft_strcmp(split[0], "./minishell") == 0)
			special_case_1(data, split);
		else
			checkcmd(split, data);
		ft_free_split(split);
		free(cmd_2);
		return ;
	}
}

void	begin_cmd(t_data *data, char *cmd)
{
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
