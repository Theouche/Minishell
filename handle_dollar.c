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

int	to_change(char *str, int j)
{
	int		i;
	char	fq;

	i = 0;
	fq = 0;
	while (i <= j)
	{
		if (str[i] == 34 || str[i] == 39)
			fq = give_fq(fq, str[i]);
		else
		{
			if (str[i] == 36 && (fq == 0 || fq == 34)
				&& str[i + 1] && str[i + 1] == '?' && i == j)
				return (2);
			if (str[i] == 36 && (fq == 0 || fq == 34)
				&& str[i + 1] && str[i + 1] != ' '
				&& str[i + 1] != 0 && str[i + 1] != 34 && i == j)
				return (1);
		}
		i++;
	}
	return (0);
}

char	*special_case(t_data *data, char *ret)
{
	char	*ret2;

	ret2 = ft_strjoin_and_free(ret, ft_itoa(exitstatus(data->status)));
	return (ret2);
}

char	*replace_dol_2(t_data *data, char *str, char *ret, int i)
{
	char	*ret2;
	int		j;

	data->env_dol = ft_calloc(sizeof(char), 100);
	j = 0;
	i++;
	while (str[i] && (str[i] != ' ' && str[i] != 39 && str[i] != 34))
		data->env_dol[j++] = str[i++];
	if (data->env_dol[0] != 0)
		ret2 = ft_strjoin_and_free(ret, ft_get_env(data, data->env_dol));
	else
	{
		ret2 = ft_strdup(ret);
		free(ret);
	}
	free(data->env_dol);
	return (ret2);
}

char	*replace_dol(t_data *data, char *str)
{
	char	*ret;
	int		i;

	ret = ft_calloc(sizeof(char), ft_strlen(str));
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != 36)
			ret = add_char(ret, str[i++]);
		if (str[i] && str[i + 1] && str[i + 1] == '?' && to_change(str, i))
		{
			ret = special_case(data, ret);
			i += 2;
		}
		else if (str[i] && str[i + 1] && to_change(str, i))
		{
			ret = replace_dol_2(data, str, ret, i);
			i++;
			while (str[i] && (str[i] != ' ' && str[i] != 39 && str[i] != 34))
				i++;
		}
		else if (str[i])
			ret = add_char(ret, str[i++]);
	}
	return (ret);
}

char	*handle_dollar(t_data *data, char *prompt)
{
	char	*fin_prompt;

	if (is_dollar(prompt) == 1 || is_dollar(prompt) == 2)
		fin_prompt = replace_dol(data, prompt);
	else
		fin_prompt = ft_strdup(prompt);
	return (fin_prompt);
}
