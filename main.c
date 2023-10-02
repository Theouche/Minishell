/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:16:23 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/22 10:50:54 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_prompt(char *name, char *split)
{
	char	*prompt;
	char	*temp;

	temp = ft_strjoin(name, split);
	temp = ft_strjoin(temp, " > ");
	temp = ft_strjoin(temp, WHITE);
	prompt = readline(temp);
	free(temp);
	free(name);
	return (prompt);
}

char	*ft_readline(void)
{
	char	**split;
	char	*name;
	char	*path;
	char	*prompt;
	int	i;

	i = 0;
	name = ft_strjoin(NAME, VIOLET);
	path = getcwd(NULL, 0);
	split = ft_split(path, '/');
	while (split[i])
		i++;
	i--;
	if (i == -1)
	{
		ft_free_split(split);
		split = malloc(sizeof(char *) * 2);
		split[0] = ft_strdup("/");
		split[1] = NULL;
		i++;
	}
	free(path);
	prompt = create_prompt(name, split[i]);
	ft_free_split(split);
	return (prompt);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	//char	**lst_cmd;
	char	*prompt;
	//t_list	*lst_cmd;

	if (argc != 1 || argv[1])
	{
		ft_printf("This program does not accept arguments\n");
		return (0);
	}
	data = malloc(sizeof(t_data) * 1);
	//lst_cmd = malloc(sizeof(t_list) * 1);
	ft_init(data, env);
	//add_history("echo $USER");
	set_signal();
	while (42)
	{
		prompt = ft_readline();
		//ft_printf("le prompte est : %s\n", prompt);
		//check_prompt(prompt);   A faire !!!!!!
		add_history(prompt);
		data->redir = 0;
		if (prompt[0])
		{
			if (ft_check_and_parse(data, prompt) == 1)
			{
				printf("les commandes sont :\n"); //plus utile ?
				check_tab(data->cmd); // plus utile ?
				printf("\n\n"); // plus utile ?
				if (ft_strcmp(data->cmd[0], "exit") == 0) // plus utile ?
				{
					// faudra probablement free des trucs !!
					break ;
				}
				begin_cmd(data);
			}
		}
		//execute_cmd(lst_cmd, env);
	}
	//ajouter fct pour free la structure !
}
