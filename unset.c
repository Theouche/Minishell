/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   unset.c	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tlorne <marvin@42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/07 14:07:39 by tlorne	#+#	#+#	 */
/*   Updated: 2023/09/07 14:07:40 by tlorne	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "minishell.h"

void	do_unset_find(t_data *data, char *unset)
{
	int		i;
	int		j;
	char	**envcpy_2;

	i = 0;
	while (data->cpyenv[i])
		i++;
	envcpy_2 = malloc(sizeof(char *) * (i));
	i = 0;
	j = 0;
	while (data->cpyenv[i])
	{
		if (ft_strncmp(data->cpyenv[i], unset, ft_strlen(unset)) != 0)
			envcpy_2[j++] = ft_strdup(data->cpyenv[i]);
		i++;
	}
	envcpy_2[j] = 0;
	ft_free_split(data->cpyenv);
	data->cpyenv = malloc(sizeof(char *) * (i));
	i = -1;
	while (envcpy_2[++i])
		data->cpyenv[i] = ft_strdup(envcpy_2[i]);
	data->cpyenv[i] = 0;
	ft_free_split(envcpy_2);
	return ;
}

void	do_unset(t_data *data, char *unset)
{
	int	i;
	int	len;

	len = ft_strlen(unset);
	i = 0;
	while (data->cpyenv[i])
	{
		if (ft_strncmp(data->cpyenv[i], unset, len) == 0)
		{
			do_unset_find(data, unset);
			return ;
		}
		i++;
	}
	return ;
}

int	check_arg_unset(char *exp)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		if (ft_isalpha(exp[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset(t_data *data, char **unset)
{
	int	i;

	i = 0;
	while (unset[++i])
	{
		if (check_arg_unset(unset[i]) == 1)
			do_unset(data, unset[i]);
		else
		{
			data->status = 1;
			ft_printf("this arg : %s is wrong\n", unset[i]);
		}
	}
}

int	apply_unset(t_data *data, char **cmd)
{
	int		i;
	int		len;
	char	**clean_cmd;

	len = 0;
	while (cmd[len])
		len++;
	clean_cmd = malloc(sizeof(char *) * (len + 1));
	clean_cmd[0] = ft_strdup(cmd[0]);
	data->status = 0;
	i = 1;
	while (cmd[i])
	{
		if (is_quote(cmd[i]) == 1)
			clean_cmd[i] = remove_quote(cmd[i]);
		else
			clean_cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	clean_cmd[len] = 0;
	ft_unset(data, clean_cmd);
	ft_free_split(clean_cmd);
	ft_free_split(cmd);
	return (5);
}
