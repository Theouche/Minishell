/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_db_droite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:45:30 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/22 16:11:46 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_bis(t_data *data, t_data *bis, char *new_cmd)
{
	ft_init(bis, data->cpyenv);
	bis->redir = data->redir;
	bis->cmd = malloc(sizeof(char *) * 2);
	bis->cmd[0] = ft_strdup(new_cmd);
	bis->cmd[1] = 0;
}

void	clean_and_resend(t_data *data, char **split)
{
	int	i;
	char	*new_cmd;
	t_data	*redir;

	new_cmd = malloc(1 * sizeof(char));
	new_cmd[0] = 0;
	i = 0;
	redir = ft_calloc(sizeof(t_data), 1);
	while (split[i][0] != '>')
	{
		new_cmd = ft_strjoin_and_free2(new_cmd, split[i]);
		if (split[i + 1][0] != '>')
		{
			//printf("############################ici###################\n");
			new_cmd = add_space(new_cmd);
			//new_cmd = ft_strjoin_and_free(new_cmd, " ");
			//printf("############################probleme###################\n");
		}
		i++;
	}
	//printf("##### la nouvelle commande est : %s\n", new_cmd);
	if (new_cmd)
	{
		ft_init_bis(data, redir, new_cmd);
		begin_cmd(redir, new_cmd);
		//ajouter fct pour free la structure !
	}
	end_prog(redir, new_cmd);
}

void	creat_doc(char	*outfile)
{
	int	new_fd_output;

	new_fd_output = open(outfile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (new_fd_output == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit(1);
	}
	if (dup2(new_fd_output, STDOUT_FILENO) == -1)
	{
		perror("Erreur lors de la redirection de la sortie");
		exit(1);
	}
	close(new_fd_output);
}

void	ft_redir_double_droite(t_data *data, char *cmd)
{
	int		orig_std_out;
	int		i;
	char	*outfile;
	char	**split;

	orig_std_out = dup(STDOUT_FILENO);
	split = ft_split(cmd, ' ');
	i = 0;
	while (split[i])
		i++;
	outfile = split[i - 1];
	creat_doc(outfile);
	clean_and_resend(data, split);
	if (dup2(orig_std_out, STDOUT_FILENO) == -1) 
	{
		perror("Erreur lors de la restauration de la sortie standard");
		exit(1);
	}
	//printf("################## ok7\n");
	ft_free_split(split);
	//printf("################## ok8\n");
	close(orig_std_out);
}
