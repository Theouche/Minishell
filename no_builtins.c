/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:10 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/12 14:58:49 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	no_builtin(t_data *data, char **env)
{
	char	*clean_cmd;
	
	(void)env;
	if (is_quote(data->fsplit[0]) == 1)
		clean_cmd = remove_quote(data->fsplit[0]);
	if (checkcmd(data->fsplit, data) == 1)
		return ;
	else
		return ;
}
