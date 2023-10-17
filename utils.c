/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:42:21 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/21 13:42:00 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_for_norm(void)
{
	ft_printf("bash: syntax error near");
	ft_printf(" unexpected token `|'\n");
	return (0);
}

int	red_not_ok(char *cmd, char c)
{
	char	**split;
	int		i;

	split = first_split(cmd, ' ');
	i = 0;
	while (split[i])
	{
		if (split[i][0] == c && !split[i + 1])
		{
			ft_free_split(split);
			ft_printf("bash: syntax error near");
			ft_printf(" unexpected token `newline'\n");
			return (1);
		}
		i++;
	}
	ft_free_split(split);
	return (0);
}

int	all_com_ok(char **cmd)
{
	int		i;
	char	c;

	i = 0;
	while (cmd[i])
	{
		if (check_only_space(cmd[i]) == 1)
			return (ft_error_for_norm());
		if (ft_strchr_red(cmd[i], '<') == 1)
		{
			c = '<';
			if (red_not_ok(cmd[i], c) == 1)
				return (0);
		}
		if (ft_strchr_red(cmd[i], '>') == 1)
		{
			c = '>';
			if (red_not_ok(cmd[i], c) == 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	exitstatus(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (status);
}
