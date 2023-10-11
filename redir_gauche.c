/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_gauche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:52:12 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/25 10:52:48 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    clean_and_resend3(char *deb)
{
    char    *buffer;
    int     res_read;

    if (ft_strcmp(deb, "<") == 0)
        return ;
    buffer = malloc((42 + 1) * sizeof(char));
    res_read = 1;
    while (res_read > 0)
    {
        //printf("ici\n");
        res_read = read(STDIN_FILENO, buffer, 42);
        buffer[res_read] = 0;
        write(STDOUT_FILENO, buffer, res_read);
        //write(STDOUT_FILENO, "ok\n", 3);
        //printf("#################### fin write\n");
    }
    //printf("#################### fin write\n");
    if (res_read == -1)
	{
		perror("Erreur lors de la lecture de l'entrée");
	}
    free(buffer);
}

int    creat_doc3(char *infile)
{
    int new_fd_input;

    new_fd_input = open(infile, O_RDONLY);
    if (new_fd_input == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
        close(new_fd_input);
        return (0);
	}
	if (dup2(new_fd_input, STDIN_FILENO) == -1)
	{
		perror("Erreur lors de la redirection de l'entrée");
	}
	close(new_fd_input);
    return (1);
}

void	ft_redir_gauche(t_data *data, char *cmd)
{
    int orig_std_in;
    int i;
    char    *infile;
    char    **split;
    (void)data;

    orig_std_in = dup(STDIN_FILENO);
    split = ft_split(cmd, ' ');
    i = 0;
    while (split[i])
        i++;
    infile = split[i - 1];
    if (creat_doc3(infile) == 1)
        clean_and_resend3(split[0]);
    if (dup2(orig_std_in, STDIN_FILENO) == -1) 
	{
		perror("Erreur lors de la restauration de la sortie standard");
		exit(1);
	}
	ft_free_split(split);
	close(orig_std_in);
}
