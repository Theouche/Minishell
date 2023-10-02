/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leudelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:58:29 by leudelin          #+#    #+#             */
/*   Updated: 2023/09/25 13:58:33 by leudelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		new_std_outin(int output_fd, int input_fd, char **cmd, t_data *data)
{
	char	*path;

	if (input_fd != STDIN_FILENO) //oldfd devient newfd = duplication de STDIN_FILENO pour le fd de la pipe (donc input_fd deviens STDIN)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != STDOUT_FILENO) //same mais avec output
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	path = recupthepath(data, cmd[0]);
	cmd[0] = recupthepath(data, cmd[0]);
	if (cmd[0])
	{
		execve(path, cmd, data->cpyenv);
		perror("execve");
	}
	else
		perror("command not found");
	return (0);
}