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

void	free_cmd(char ***cmd, int num_cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num_cmd)
	{
		while(cmd[i][j])
		{
			free(cmd[i][j]);
			j++;
		}
		free(cmd[i]);
		i++;
	}
}

int		ft_pipe1(int num_cmd, int **pipefd, char ***cmd, t_data *data)
{
	int		input_fd;
	int		output_fd;
	int		i;

	i = 0;
	input_fd = STDIN_FILENO;
	while (i < num_cmd)
	{
		if (num_cmd - 1 == i) //si c'est la derniere commande (par rapport a l'index)
			output_fd = STDOUT_FILENO;
		else
			output_fd = pipefd[i][1]; //sinon on redirige vers le stdout de la pipe
		checkcmdpipe(input_fd, output_fd,  cmd[i], data);
		if (i > 0) //si c'est ni la 1ere ni la derniere on ferme le pipedfd precedent car pu besoin
			close(pipefd[i - 1][0]); //- 1 du coup car par rapport a l'index tt est decaler tmtc
		if (i < num_cmd - 1) //si c'est pas la derniere on redirige vers le pipefd de lecture
		{
			input_fd = pipefd[i][0];
			close(pipefd[i][1]);
		}
		i++;
	}
	return (0);
}

int		ft_pipe(char ***cmd, int num_cmd, t_data *data)
{
	int		**pipefd;
	int		i;

	i = 0;
	pipefd = malloc(sizeof(int *) * num_cmd - 1); //malloc general par rapport au nombre de commande
	while (i < num_cmd - 1)
	{
		pipefd[i] = malloc(2 * sizeof(int)); //malloc pour une seule pipe (*2 car pour lecture et ecriture)
		if (pipe(pipefd[i]) == -1)
		{
			perror("error creating pipe");
			exit (1);
		}
		i++;
	}
	ft_pipe1(num_cmd, pipefd, cmd, data);
	/*i = 0;
	while (i < num_cmd - 1)
	{
		free(pipefd[i]);
		i++;
	}*/
	return (0);
}


int		forpipe(char **cmd, t_data *data)
{
	char	***cmds;
	int		num_cmd;
	int		i;

	num_cmd = 0;
	while (cmd[num_cmd] != NULL)
		num_cmd++;
	cmds = malloc(sizeof(char **) * num_cmd);
	if (cmds == NULL)
	{
		perror("no command");
		return (1);
	}
	i = 0;
	while (cmd[i] != NULL)
	{
		cmds[i] = ft_split(cmd[i], ' ');
		i++;
	}
	//printf("salut c'est fanta");
	ft_pipe(cmds, num_cmd, data);
	free_cmd(cmds, num_cmd);
	return (0);
}

//0 = stdin;
//1 = stdout;
//dup2(oldfd, newfd)

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
