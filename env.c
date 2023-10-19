/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:00:55 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/12 10:51:55 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	special_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->cpyenv[++i])
	{
		ft_printf("declare -x %s\n", data->cpyenv[i]);
	}
}

int	apply_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->cpyenv[++i])
	{
		ft_printf("%s\n", data->cpyenv[i]);
	}
	data->status = 0;
	return (3);
}
