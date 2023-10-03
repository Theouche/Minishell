/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_db_gauche.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:49:15 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/25 14:49:28 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    do_until_delim(t_data *data, char *comm, char *delim)
{
    char    *line;
    char    *tempcmd;
    char    *finalcmd;
    t_data  *redir;

    line = readline("heredoc> ");
    redir = malloc(sizeof(t_data));
    while (42)
    {
        //printf("%s\n", line);
        if (ft_strcmp(line, delim) != 0)
        {
            //printf("not delim\n");
            //tempcmd = ft_strjoin_and_free(line, " >> temp.txt");
            tempcmd = ft_strjoin(line, " >> temp.txt");
            //printf("tempcmd vaut %s\n", tempcmd);
            tempcmd = ft_strjoin_and_free1("echo ", tempcmd);
            //tempcmd = ft_strjoin("echo ", tempcmd);
            //printf("tempcmd 2 vaut %s\n", tempcmd);
            ft_redir_double_droite(data, tempcmd);
            free(tempcmd);
            //printf("ok\n");
        }
        if (ft_strcmp(line, delim) == 0)
        {
            //printf("#########debut fin redi gauche \n");
            finalcmd = ft_strjoin(comm, " < temp.txt");
            //printf("#########final cmd vaut %s\n", finalcmd);
            ft_init_bis(data, redir, finalcmd);
            //printf("#########fin init donc deb exec com\n");
		    begin_cmd(redir, finalcmd);
            //printf("####fin begin cmd\n");
            unlink("temp.txt");
            free(line);
            //ajouter fct pour free la structure !
            break ;
        }
        free(line);
        line = readline("heredoc> ");
    }
}

void	ft_redir_double_gauche(t_data *data, char *cmd)
{
    char    **split;
    char    *comm;
    char    *delim;

    split = ft_split(cmd, ' ');
    delim = split[2];
    comm = split[0];
    do_until_delim(data, comm, delim);
    ft_free_split(split);
}