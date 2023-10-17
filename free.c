/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:19:32 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/08 11:20:06 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void    free_struct(t_data *data, char *new_cmd)
{
    if (new_cmd)
        free(new_cmd);
}*/

void	end_turn(t_data *data, char *prompt)
{
	if (prompt)
		free(prompt);
	if (data->fsplit)
		ft_free_split(data->fsplit);
	if (data->cmd)
		ft_free_split(data->cmd);
	if (data->prompt)
		free(data->prompt);
}

void	end_prog(t_data *data, char *prompt)
{
	end_turn(data, prompt);
	if (data->pwd)
		free(data->pwd);
	if (data->path)
		free(data->path);
	if (data->home)
		free(data->home);
	if (data->cpyenv)
		ft_free_split(data->cpyenv);
	free(data);
}

int	is_a_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_end(t_data *data, char *prompt)
{
	char	**split;
	int		ex;

	if (ft_count_word(data->cmd[0], ' ') > 2)
	{
		end_turn(data, prompt);
		ft_printf("exit: too many arguments\n");
		return (1);
	}
	split = ft_split(data->cmd[0], ' ');
	end_prog(data, prompt);
	if (split[1])
	{
		ex = 2;
		if (is_a_number(split[1]) == 1)
			ex = ft_atoi(split[1]);
		else
			ft_printf("exit: numeric argument required\n");
		ft_free_split(split);
		exit(ex);
	}
	exit(0);
}
