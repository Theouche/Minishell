/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:11:19 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/02 12:22:07 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_i(char *cmd, int i)
{
	char	c;

	if (cmd[i] == '-' && cmd[i + 1] == 'n')
		return (2);
	if (cmd[i] == 34 || cmd[i] == 39)
	{
		c = cmd[i];
		if (cmd[i + 1] == '-' && cmd[i + 2] == 'n' && cmd[i +3] == c)
			return (4);
	}
	return (0);
}

int	check_arg(char *cmd, int i)
{
	char	c;

	if (cmd[i] == '-' && cmd[i + 1] == 'n')
		return (1);
	if (cmd[i] == 34 || cmd[i] == 39)
	{
		c = cmd[i];
		if (cmd[i + 1] == '-' && cmd[i + 2] == 'n' && cmd[i +3] == c)
			return (1);
	}
	return (0);
}

void	echo_w_q(char *cmd)
{
	int	i;
	int	arg;
	char	fq;

	i = 4;
	while (cmd[i] && ((cmd[i]>= 9 && cmd[i] <= 13) || cmd[i] == 32))
		i++;
	arg = check_arg(cmd, i);
	i += go_i(cmd, i);
	while (cmd[i] && ((cmd[i]>= 9 && cmd[i] <= 13) || cmd[i] == 32))
		i++;
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
		{
			fq = cmd[i++];
			while (cmd[i] && cmd[i] != fq)
				ft_printf("%c", cmd[i++]);
			i++;
		}
		else
			ft_printf("%c", cmd[i++]);
	}
	if (arg == 0)
		ft_printf("\n");
}

int	is_quote_echo(char *cmd)
{
	int	i;

	i = 4;
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

int	apply_echo(char *cmd)
{
	int	i;
	int	arg;
	//char	*cmd;

	i = 4;
	arg = 0;
	//cmd = data->fsplit[0];
	//ft_printf("debut fonction echo \n");
	if (is_quote_echo(cmd))
	{
		echo_w_q(cmd);
		return (1);
	}
	while (cmd[i] && ((cmd[i]>= 9 && cmd[i] <= 13) || cmd[i] == 32))
		i++;
	if (cmd[i] == '-' && cmd[i + 1] == 'n')
	{
		arg = 1;
		i = i + 2;
	}
	while (cmd[i] && ((cmd[i]>= 9 && cmd[i] <= 13) || cmd[i] == 32))
                i++;
	while (cmd[i])
	{
		ft_printf("%c", cmd[i]);
		i++;
	}
	if (arg == 0)
		ft_printf("\n");
	return (1);	
}
