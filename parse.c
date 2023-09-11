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
/*
char	*ft_strjoin_nfree(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	//printf("ok4\n");
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	printf("ok 3 \n");
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == 0)
		return (NULL);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + j] = 0;
	free(s1);
	//free(s2);
	return (str);
}

char	*add_spe(char *cmd_split)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(cmd_split) +1));
	while (cmd_split[i])
	{
		str[i] = cmd_split[i];
		i++;
	}
	str[i] = 0;
	return (str);

}

char	**get_cmd(char **cmd_split)
{
	char	**lst_cmd;
	int	i;
	int	j;

	i = 0;
	while (cmd_split[i])
		i++;
	lst_cmd = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	//printf("debut recup\n");
	while (cmd_split[i])
	{
		//printf("tour num %d \n", j);
		lst_cmd[j] = malloc(sizeof(char) * 1);
		lst_cmd[j] = 0;
		while (cmd_split[i] && cmd_split[i][0] != 60 && cmd_split[i][0] != 62 && cmd_split[i][0] != 124)
                {
			//printf("ok \n");
                        lst_cmd[j] = ft_strjoin_nfree(lst_cmd[j], cmd_split[i]);
                        lst_cmd[j] = ft_strjoin_nfree(lst_cmd[j], " ");
                        i++;
		}
		//printf("ok 2\n");
		if (cmd_split[i] && cmd_split[i][0] == 124)
		{
			//lst_cmd[j] = ft_strjoin_nfree(lst_cmd[j], "pipe");
			lst_cmd[++j] = add_spe(cmd_split[i]);
			//lst_cmd[j] = malloc(sizeof(char) * 2);
			//lst_cmd[j][0] = 124;
			//lst_cmd[j][1] = 0;
			i++;
		}
		else if (cmd_split[i] && (cmd_split[i][0] == 60 || cmd_split[i][0] == 62))
		{
			//lst_cmd[j] = ft_strjoin_nfree(lst_cmd[j], "red");
			lst_cmd[++j] = add_spe(cmd_split[i]);
			i++;
		}
		else
		{
			lst_cmd[j] = ft_strjoin_nfree(lst_cmd[j], "end");
		}
		j++;
	}
	lst_cmd[j] = 0;
	return (lst_cmd);
}

void	print_cmd(char **list_cmd)
{
	int	i;

	i = 0;
	while (list_cmd[i])
		printf("%s\n", list_cmd[i++]);
}
*/

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
	//lst_cmd = malloc(sizeof(t_list) * 1);
	temp = malloc(sizeof(t_list) * 1);
	printf("debut cmd\n");
	while (cmd_split[i])
	{
		//cmd = malloc(sizeof(char) * 1);
		printf("%d\n", i);
		while (cmd_split[i] && cmd_split[i][0] != 60 && cmd_split[i][0] != 62 && cmd_split[i][0] != 124)
		{
			cmd = ft_strjoin(cmd, cmd_split[i]);
			cmd = ft_strjoin(cmd, " ");
			i++;
			printf("%s\n", cmd);
		}
		printf("%s\n", cmd_split[i]);
		if (cmd_split[i] && cmd_split[i][0] == 124)
		{
			//write(1,"debut add list\n", 15);
			printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 1, 0);
			printf("check temp avec pip!!!!!!!!!!\n");
			printf("%s\n", temp->cmd);
			printf("%d\n", temp->pipe);
			printf("%d\n", temp->redir);
			//ft_lstadd_back(lst_cmd, ft_lstnew(cmd, 1, 0));
			i++;
			printf("avec pipe\n");
		}
		else if (cmd_split[i] && (cmd_split[i][0] == 60 || cmd_split[i][0] == 62))
		{
			//ft_lstadd_back(lst_cmd, ft_lstnew(cmd, 0, 1));
			printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 0, 1);
			printf("check temp avec r!!!!!!!!!!\n");
			printf("%s\n", temp->cmd);
			printf("%d\n", temp->pipe);
			printf("%d\n", temp->redir);
			i++;
			printf("avec redirection\n");
		}
		else
		{
			//ft_lstadd_back(lst_cmd, ft_lstnew(cmd, 0, 0));
			printf("%s\n", cmd);
			temp = ft_lstnew(cmd, 0, 0);
			printf("check temp no spe!!!!!!!!!!\n");
			printf("%s\n", temp->cmd);
			printf("%d\n", temp->pipe);
			printf("%d\n", temp->redir);
			printf("no spe\n");
		}
		cmd[0] = 0;
		printf("add back\n");
		print_cmd(*lst_cmd);
		if (ft == 1)
		{
			ft = 0;
			*lst_cmd = temp;
		}
		else
		{
			//ft_lstadd_back(lst_cmd, temp);
			last_elem = ft_lstlast(*lst_cmd);
			last_elem->next = temp;
		}
		printf("add back verif apres\n");
		print_cmd(*lst_cmd);
		/*if (!*lst_cmd)
		{
			printf("ini list\n");
			*lst_cmd = temp;
			//printf("%s\n", lst_cmd->cmd);
                	//printf("%d\n", lst_cmd->pipe);
                	//printf("%d\n", lst_cmd->redir);
			//ft_lstadd_back(lst_cmd, temp);
		}
		else
		{
			printf("ajout lst avec fct\n");
			//lst_cmd->next = temp;
			//lst_cmd = lst_cmd->next;
			ft_lstadd_back(lst_cmd, temp);
		}*/
		//free(cmd);
		//i++;
	}
	free(cmd);
}

void	print_cmd(t_list *lst_cmd)
{
	int	i = 0;
	printf("debut verif\n");
	while (lst_cmd)
	{
		printf("%d\n", i);
		printf("%s\n", lst_cmd->cmd);
		printf("%d\n", lst_cmd->pipe);
		printf("%d\n", lst_cmd->redir);
		lst_cmd = lst_cmd->next;
		i++;
	}
}

void	ft_parse(char *prompt, t_list **lst_cmd)
{
	char	**cmd_split;
	//char	**list_cmd;
	//int	i;
	//char	*pathway;
	//void(data);

	cmd_split = ft_split(prompt, 32);
	int i = 0;
	while (cmd_split[i])
		printf("%s\n", cmd_split[i++]);
	//lst_cmd = malloc(sizeof(t_list) * 1);
	printf("debut cmd\n");
	//list_cmd = get_cmd(cmd_split, lst_cmd);
	get_cmd(cmd_split, lst_cmd);
	printf("fin cmd\n");
	//print_cmd(list_cmd);
	printf("fin verif\n");
	//return (list_cmd);
	//print_cmd(*lst_cmd);
	/*i = 0;
	while (cmd_split[i])
	{
		if (check_word(cmd_split[i]) == 1 && cmd_split[i + 1])
		{
			i += ft_echo(cmd_split, i);
		}
		i++;
	}*/
	//	ft_printf("%s\n", split[i++]);
	//pathway = ft_strjoin("/usr/bin/", cmd_split[0]);
	//execve(pathway, cmd_split, NULL);
}
