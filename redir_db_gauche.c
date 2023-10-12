/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   redir_db_gauche.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tlorne <marvin@42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/25 14:49:15 by tlorne	#+#	#+#	 */
/*   Updated: 2023/09/25 14:49:28 by tlorne	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "minishell.h"

void	do_until_delim(t_data *data, char *comm, char *delim)
{
	char	*line;
	char	*tempcmd;
	char	*finalcmd;
	t_data	*redir;

	line = readline("heredoc> ");
	redir = ft_calloc(sizeof(t_data), 1);
	while (42)
	{
		if (ft_strcmp(line, delim) != 0)
		{
			tempcmd = ft_strjoin(line, " >> temp.txt");
			tempcmd = ft_strjoin_and_free1("echo ", tempcmd);
			ft_redir_double_droite(data, tempcmd);
			free(tempcmd);
		}
		if (ft_strcmp(line, delim) == 0)
		{
			if (comm[0])
			{
				finalcmd = ft_strjoin(comm, " < temp.txt");
				ft_init_bis(data, redir, finalcmd);
				begin_cmd(redir, finalcmd);
				free(finalcmd);
			}
			else
				free(comm);
			unlink("temp.txt");
			end_prog(redir, line);
			break ;
		}
		free(line);
		line = readline("heredoc> ");
	}
}

void	ft_redir_double_gauche(t_data *data, char *cmd)
{
	char	**split;
	char	*comm;
	char	*delim;
	int		i;

	i = 0;
	split = ft_split(cmd, ' ');
	while (split[i] && ft_strcmp(split[i], "<<") != 0)
		i++;
	delim = split[i + 1];
	if (i != 0)
		comm = split[i - 1];
	else
		comm = ft_calloc(sizeof(char), 1);
	do_until_delim(data, comm, delim);
	ft_free_split(split);
}
