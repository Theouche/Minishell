/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:28:18 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/26 10:29:04 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_and_free1(char *s1, char *s2)
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
	free(s2);
	str[i + j] = 0;
	return (str);
}

char	*ft_strjoin_and_free2(char *s1, char *s2)
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
	str[i + j] = 0;
	return (str);
}

void	norm(t_data *data, t_data *redir, char *new_cmd)
{
	if (new_cmd)
	{
		ft_init_bis(data, redir, new_cmd);
		begin_cmd(redir, new_cmd);
	}
}

char	**remp_tab(char **split, char *tf)
{
	char	**outfile;
	int		i;
	int		j;

	outfile = ft_calloc(sizeof(char *), len_tab(split));
	i = 0;
	j = 0;
	while (split[i] && split[i + 1])
	{
		if (ft_strcmp(split[i], tf) == 0)
			outfile[j++] = ft_strdup(split[i + 1]);
		i++;
	}
	return (outfile);
}
