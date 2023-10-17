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

char	*replace_dol_2(t_data *data, char *str, char *ret, int i)
{
	(void)data;
	if (str[i])
	{
		while (str[i])
		{
			ret = add_char(ret, str[i]);
			i++;
		}
	}
	return (ret);
}

char	*replace_dol(t_data *data, char *str)
{
	char	*ret;
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
	data->env_dol = malloc(sizeof(char) * 100);
	j = 0;
	while (str[i] && (str[i] != ' ' && str[i] != 39 && str[i] != 34))
		data->env_dol[j++] = str[i++];
	data->env_dol[j] = 0;
	ret = ft_strjoin_and_free(ret, ft_get_env(data, data->env_dol));
	ret = replace_dol_2(data, str, ret, i);
	free(data->env_dol);
	return (ret);
}

char	*special_case_suite(t_data *data, char *str, char *ret, int i)
{
	int		len;

	(void)data;
	len = ft_strlen(str);
	if (str[i])
	{
		while (str[i])
		{
			ret = add_char(ret, str[i]);
			i++;
		}
	}
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
	ret = special_case_suite(data, str, ret, i);
	return (ret);
}

char	*handle_dollar(t_data *data, char *prompt)
{
	char	*fin_prompt;

	if (is_dollar(prompt) == 1)
		fin_prompt = replace_dol(data, prompt);
	else if (is_dollar(prompt) == 2)
		fin_prompt = special_case(data, prompt);
	else
		fin_prompt = ft_strdup(prompt);
	return (fin_prompt);
}
