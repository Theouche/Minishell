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

char	**first_split(char *p, char c)
{
	int		i;
	int		j;
	int		pos;
	char	q;
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
			{
				//printf("quote trouve %c a l'index %d\n", p[i], i);
				q = p[i];
				i++;
				while (p[i] != q)
					i++;
				//printf("on est a l'index %d, donc au car %c \n", i, p[i]);
			}
			i++;
		}
		if (pos != i)
		{
			tab[j] = ft_strndup_ms(p + pos, i - pos);
			j++;
		}
		if (p[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}

int	check_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] && str[i] != 34)
				i++;
			if (str[i] == 0)
				return (0);
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
				i++;
			if (str[i] == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
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

	//tmp = ft_split(data->fsplit[i], ' ');
	//printf("ok\n");
	//faire un remove space ? et tout copier dans cmd ?
	printf("fsplit vaut :%s\n", data->fsplit[i]);
	tmp = ft_remove_first_space(data->fsplit[i]);
	//old version
	printf("tmp vaut :%s\n", tmp);
	if (tmp)
		data->cmd[i] = ft_strdup(tmp);
	else
	{
		//free(tmp);
		ft_free_split(data->fsplit);
		ft_free_split(data->cmd);
		return (0);
	}
	printf("%s\n", data->cmd[i]);
	//free(tmp);
	return (1);
}

int	ft_check_and_parse(t_data *data, char *prompt)
{
	int	i;

	i = 0;
	//printf("%d\n", check_quote(prompt));
	if (!check_quote(prompt))
	{
		ft_printf("au moins une quote n'est pas ferme\n");
		return (0) ;
	}
	data->prompt = handle_dollar(data, prompt);
	printf("##### data->prompt vaut : %s\n\n", data->prompt);
	data->fsplit = first_split(data->prompt, '|');
	//printf("les differentes parties du prompt sont : \n");
	//check_tab(data->fsplit);
	printf("\n\n");
	get_num_pipe(data);
	data->cmd = malloc(sizeof(char *) * (data->num_pip) + 2);
	data->cmd[data->num_pip + 1] = 0;
	while (data->fsplit[i])
	{
		printf("ok %d\n", i);
		if (!get_cmd(data, i))
			return (0) ;
		i++;
	}
	printf("les differentes commandes sont : \n");
	check_tab(data->cmd);
	return (1);
	//begin_cmd(data, env);
	//printf("fin ?\n");
}
