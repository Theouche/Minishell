/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:33:06 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/21 14:26:36 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	advance(int i, char *p)
{
	char	q;

	q = p[i];
	i++;
	while (p[i] != q)
		i++;
	return (i);
}

char	**first_split(char *p, char c)
{
	int		i;
	int		j;
	int		pos;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count_word_ms(p, c) + 1));
	while (p[i])
	{
		pos = i;
		while (p[i] != c && p[i])
		{
			if (p[i] == 34 || p[i] == 39)
				i = advance(i, p);
			i++;
		}
		if (pos != i)
			tab[j++] = ft_strndup_ms(p + pos, i - pos);
		if (p[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}

void	get_num_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (data->fsplit[i])
		i++;
	data->num_pip = i - 1;
}

int	get_cmd(t_data *data, int i)
{
	char	*tmp;

	tmp = ft_remove_first_space(data->fsplit[i]);
	if (tmp)
		data->cmd[i] = ft_strdup(tmp);
	else
	{
		ft_free_split(data->fsplit);
		ft_free_split(data->cmd);
		return (0);
	}
	free(tmp);
	return (1);
}

int	ft_check_and_parse(t_data *data, char *prompt)
{
	int	i;

	i = 0;
	if (!check_quote(prompt))
	{
		ft_printf("au moins une quote n'est pas ferme\n");
		return (0);
	}
	if (check_only_space(prompt) == 1)
		return (0);
	data->prompt = handle_dollar(data, prompt);
	data->fsplit = first_split(data->prompt, '|');
	get_num_pipe(data);
	data->cmd = ft_calloc(sizeof(char *), (data->num_pip) + 2);
	data->cmd[data->num_pip + 1] = 0;
	while (data->fsplit[i])
	{
		if (!get_cmd(data, i))
			return (0);
		i++;
	}
	if (all_com_ok(data->cmd) == 1)
		return (1);
	else
		return (0);
}
