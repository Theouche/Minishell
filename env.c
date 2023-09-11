/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:00:55 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/04 11:13:01 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	apply_env(t_data *data, char **env)
{
	int	i;
	//(void)data;
	(void)env;

	i = -1;
	while (data->cpyenv[++i])
		ft_printf("%d ---- %s\n", i, data->cpyenv[i]);
	//ft_printf("%s\n", getcwd(NULL, 0));
	return (3);
}
