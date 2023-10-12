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
	temp = ft_strjoin_and_free2(temp, " > ");
	temp = ft_strjoin_and_free2(temp, WHITE);
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
	int		i;

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
	prompt = create_prompt(name, split[i]);
	free(path);
	ft_free_split(split);
	return (prompt);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*prompt;
	int		not;

	if (argc != 1 || argv[1])
	{
		ft_printf("This program does not accept arguments\n");
		return (0);
	}
	data = malloc(sizeof(t_data) * 1);
	ft_init(data, env);
	set_signal();
	while (42)
	{
		not = 0;
		prompt = ft_readline();
		if (!prompt)
			break ;
		add_history("ls -la | grep drwxr | wc");
		add_history(prompt);
		data->redir = 0;
		if (prompt[0] != 0)
		{
			not = 1;
			if (ft_check_and_parse(data, prompt) == 1)
			{
				if (ft_strcmp(data->cmd[0], "exit") == 0)
				{
					if (check_shlvl(data) == 1 || check_shlvl(data) == 0)
					{
						end_prog(data, prompt);
						break ;
					}
					else
						reduce_shlvl(data);
				}
				else
				{
					if (data->cmd[0])
					{
						if (data->num_pip >= 1)
							forpipe(data->cmd, data);
						else
							begin_cmd(data, data->cmd[0]);
					}
				}
			}
			end_turn(data, prompt);
		}
		if (not == 0)
			free(prompt);
	}
}
