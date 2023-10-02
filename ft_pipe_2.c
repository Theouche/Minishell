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

int		checkcmdpipe(int input_fd, int output_fd, char **cmd, t_data *data)
{
	pid_t	pid;
	int		status;
	
	pid = fork();
	if (pid == 0)
		new_std_outin(output_fd, input_fd, cmd, data);
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (0);
	}
	else
	{
		perror("fork");
		exit (1);
	}
	return (0);
}