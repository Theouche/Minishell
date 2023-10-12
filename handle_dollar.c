/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tlorne <marvin@42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/28 11:41:38 by tlorne	#+#	#+#	 */
/*   Updated: 2023/10/12 14:22:03 by leudelin         ###   ########.fr       */
/*	*/
/* ************************************************************************** */

#include "minishell.h"

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
	char	*find;

	i = 0;
	while (i < len_tab(data->cpyenv) && ft_strncmp(data->cpyenv[i], sch, ft_strlen(sch)) != 0)
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

char	*replace_dol(t_data *data, char *str)
{
	char	*ret;
	char	*env;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != 36)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = 0;
	env = malloc(sizeof(char) * 100);
	j = 0;
	while (str[i] && (str[i] != ' ' && str[i] != 39 && str[i] != 34))
		env[j++] = str[i++];
	env[j] = 0;
	ret = ft_strjoin_and_free(ret, ft_get_env(data, env));
	if (str[i])
	{
		while (str[i])
		{
			ret = add_char(ret, str[i]);
			i++;
		}
		ret[ft_strlen(str) - ft_strlen(env) + ft_strlen(ft_get_env(data, env))] = 0;
	}
	else
		ret[ft_strlen(str) - ft_strlen(env) + ft_strlen(ft_get_env(data, env))] = 0;
	return (ret);
}

char	*special_case(t_data *data, char *str)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != 36)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = 0;
	ret = ft_strjoin_and_free(ret, ft_itoa(exitstatus(data->status)));
	i++;
	if (str[i])
	{
		while (str[i])
		{
			ret = add_char(ret, str[i]);
			i++;
		}
		ret[ft_strlen(str) - 1 + ft_strlen(ft_itoa(exitstatus(data->status)))] = 0;
	}
	else
		ret[ft_strlen(str) - 1 + ft_strlen(ft_itoa(exitstatus(data->status)))] = 0;
	return (ret);
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
			if (str[i] == 36 && (fq == 0 || fq == 34) && str[i + 1] && str[i + 1] == '?')
				return (2);
			if (str[i] == 36 && (fq == 0 || fq == 34) && str[i + 1] && str[i + 1] != ' ' && str[i + 1] != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

char	*handle_dollar(t_data *data, char *prompt)
{
	char	*fin_prompt;

	if (is_dollar(prompt) == 1)
		fin_prompt = replace_dol(data, prompt);
	if (is_dollar(prompt) == 2)
		fin_prompt = special_case(data, prompt);
	else
		fin_prompt = ft_strdup(prompt);
	return (fin_prompt);
}
