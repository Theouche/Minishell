/* ************************************************************************** */
/*  */
/*  :::  ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*  +:+ +:+ +:+  */
/*   By: tlorne <marvin@42.fr>  +#+  +:+	 +#+  */
/*  +#+#+#+#+#+   +#+   */
/*   Created: 2023/09/29 13:55:27 by tlorne #+#  #+#	*/
/*   Updated: 2023/10/12 14:22:34 by leudelin         ###   ########.fr       */
/*  */
/* ************************************************************************** */

#include "minishell.h"

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*char_vide(void)
{
	char	*find;

	find = malloc(sizeof(char) * 1);
	find[0] = 0;
	return (find);
}

char	*add_char(char *str, char c)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = 0;
	free(str);
	return (new_str);
}

char	*ft_get_env(t_data *data, char *sch)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*find;

	i = 0;
	len = ft_strlen(sch);
	while (data->cpyenv[i] && ft_strncmp(data->cpyenv[i], sch, len) != 0)
		i++;
	if (i == len_tab(data->cpyenv))
		return (char_vide());
	find = malloc(sizeof(char) * ft_strlen(data->cpyenv[i]));
	j = ft_strlen(sch) + 1;
	k = 0;
	while (data->cpyenv[i][j])
	{
		find[k] = data->cpyenv[i][j];
		k++;
		j++;
	}
	find[k] = 0;
	return (find);
}

int	is_dollar(char *str)
{
	int		i;
	char	fq;

	i = 0;
	fq = 0;
	while (str[i])
	{
		if ((str[i] == 34 || str[i] == 39) && fq != 0)
			fq = 0;
		else if (str[i] == 34 || str[i] == 39)
			fq = str[i];
		else
		{
			if (str[i] == 36 && (fq == 0 || fq == 34)
				&& str[i + 1] && str[i + 1] == '?')
				return (2);
			if (str[i] == 36 && (fq == 0 || fq == 34)
				&& str[i + 1] && str[i + 1] != ' ' && str[i + 1] != 0)
				return (1);
		}
		i++;
	}
	return (0);
}
