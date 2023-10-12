/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:27:59 by tlorne            #+#    #+#             */
/*   Updated: 2023/08/31 10:52:33 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_word(char *word)
{
	if (ft_strncmp(word, "echo", 4) == 0)
		return (1);
	return (0);
}

void	get_cmd(char **cmd_split, t_list **lst_cmd)
{
	int		i;
	int		ft;
	char	*cmd;
	t_list	*temp;
	t_list	*last_elem;

	i = 0;
	ft = 1;
	cmd = malloc(sizeof(char) * 1);
	cmd[0] = 0;
	temp = malloc(sizeof(t_list) * 1);
	ft_printf("debut cmd\n");
	while (cmd_split[i])
	{
		ft_printf("%d\n", i);
		while (cmd_split[i] && cmd_split[i][0] != 60 && cmd_split[i][0] != 62 && cmd_split[i][0] != 124)
		{
			cmd = ft_strjoin(cmd, cmd_split[i]);
			cmd = ft_strjoin(cmd, " ");
			i++;
			ft_printf("%s\n", cmd);
		}
		ft_printf("%s\n", cmd_split[i]);
		if (cmd_split[i] && cmd_split[i][0] == 124)
		{
			ft_printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 1, 0);
			ft_printf("check temp avec pip!!!!!!!!!!\n");
			ft_printf("%s\n", temp->cmd);
			ft_printf("%d\n", temp->pipe);
			ft_printf("%d\n", temp->redir);
			i++;
			ft_printf("avec pipe\n");
		}
		else if (cmd_split[i] && (cmd_split[i][0] == 60 || cmd_split[i][0] == 62))
		{
			ft_printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 0, 1);
			ft_printf("check temp avec r!!!!!!!!!!\n");
			ft_printf("%s\n", temp->cmd);
			ft_printf("%d\n", temp->pipe);
			ft_printf("%d\n", temp->redir);
			i++;
			ft_printf("avec redirection\n");
		}
		else
		{
			ft_printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 0, 0);
			ft_printf("check temp no spe!!!!!!!!!!\n");
			ft_printf("%s\n", temp->cmd);
			ft_printf("%d\n", temp->pipe);
			ft_printf("%d\n", temp->redir);
			ft_printf("no spe\n");
		}
		cmd[0] = 0;
		ft_printf("add back\n");
		print_cmd(*lst_cmd);
		if (ft == 1)
		{
			ft = 0;
			*lst_cmd = temp;
		}
		else
		{
			last_elem = ft_lstlast(*lst_cmd);
			last_elem->next = temp;
		}
		ft_printf("add back verif apres\n");
		print_cmd(*lst_cmd);
	}
	free(cmd);
}

void	print_cmd(t_list *lst_cmd)
{
	int	i = 0;
	ft_printf("debut verif\n");
	while (lst_cmd)
	{
		ft_printf("%d\n", i);
		ft_printf("%s\n", lst_cmd->cmd);
		ft_printf("%d\n", lst_cmd->pipe);
		ft_printf("%d\n", lst_cmd->redir);
		lst_cmd = lst_cmd->next;
		i++;
	}
}

void	ft_parse(char *prompt, t_list **lst_cmd)
{
	char	**cmd_split;

	cmd_split = ft_split(prompt, 32);
	int i = 0;
	while (cmd_split[i])
		ft_printf("%s\n", cmd_split[i++]);
	ft_printf("debut cmd\n");
	get_cmd(cmd_split, lst_cmd);
	ft_printf("fin cmd\n");
	ft_printf("fin verif\n");
}
