/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:16:35 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/22 15:34:50 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_space(char *cmd)
{
	int	i;
	char	*cmd_ws;

	i = ft_strlen(cmd);
	cmd_ws = malloc(sizeof(char) * i + 2);
	i = 0;
	while (cmd[i])
	{
		cmd_ws[i] = cmd[i];
		i++;
	}
	cmd_ws[i++] = ' ';
	cmd_ws[i] = 0;
	return (cmd_ws);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	free(s2);
	str[i + j] = 0;
	return (str);
}

int	ft_strchr_dbred(char *cmd, char chev)
{
	int	i;
	char	q;

	i = 0;
	while (cmd[i])
	{
		//printf(" #### vison ++ rech, le caract vaut %c de la phrase %s dans le tour %d\n", cmd[i], cmd, i);
		if (cmd[i] == 34 || cmd[i] == 39)
		{
			q = cmd[i++];
			//printf("#### quote trouve et vaut %c\n", q);
			while (cmd[i] != q)
				i++;
		}
		if (cmd[i] && cmd[i + 1])
		{
			if (cmd[i] == chev && cmd[i + 1] == chev)
			{
				//printf("############# >> trouve######\n");
				return (1);
			}
			i++;
		}
		else
			break ;
	}
	return (0);
}

int	ft_strchr_red(char *cmd, char chev)
{
	int	i;
	char	q;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
		{
			q = cmd[i++];
			while (cmd[i] != q)
				 i++;
		}
		if (cmd[i])
		{
			if (cmd[i] == chev)
				return (1);
			i++;
		}
		else
			break ;
	}
	return (0);
}
