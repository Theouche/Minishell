/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   redir_droite.c                                     :+:      :+:    :+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tlorne <marvin@42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/25 10:18:10 by tlorne	#+#	#+#	 */
/*   Updated: 2023/10/12 17:41:08 by leudelin         ###   ########.fr       */
/*	*/
/* ************************************************************************** */

#include "minishell.h"

void	clean_and_resend2(t_data *data, char **split)
{
	int		i;
	char	*new_cmd;
	t_data	*redir;

	if (ft_strcmp(split[0], ">") == 0)
		return ;
	new_cmd = malloc(1 * sizeof(char));
	new_cmd[0] = 0;
	i = 0;
	redir = ft_calloc(sizeof(t_data), 1);
	while (split[i])
	{
		if (split[i][0] == '>' && split[i + 1])
			i += 2;
		else
		{
			new_cmd = ft_strjoin_and_free2(new_cmd, split[i]);
			new_cmd = add_space(new_cmd);
			i++;
		}
	}
	norm(data, redir, new_cmd);
	end_prog(redir, new_cmd);
}

void	creat_doc2(char **outfile)
{
	int	fd_out;
	int	i;

	i = 0;
	while ((i < len_tab(outfile) - 1) && outfile[i])
		open(outfile[i++], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	fd_out = open(outfile[i], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_free_split(outfile);
	if (fd_out == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit(1);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("Erreur lors de la redirection de la sortie");
		exit(1);
	}
	close(fd_out);
}

void	ft_redir_droite(t_data *data, char *cmd)
{
	int		orig_std_out;
	char	**outfile;
	char	**split;

	orig_std_out = dup(STDOUT_FILENO);
	split = first_split(cmd, ' ');
	outfile = remp_tab(split, ">");
	creat_doc2(outfile);
	clean_and_resend2(data, split);
	if (dup2(orig_std_out, STDOUT_FILENO) == -1)
	{
		perror("Erreur lors de la restauration de la sortie standard");
		exit(1);
	}
	ft_free_split(split);
	close(orig_std_out);
}
