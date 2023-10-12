/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:43:50 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/12 10:44:03 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_shlvl(t_data *data)
{
    int     i;
    int     shlvl;
    char    *temp;

    i = 0;
    while (data->cpyenv[i] && strncmp(data->cpyenv[i], "SHLVL", 5) != 0)
		i++;
	if (data->cpyenv[i] && strncmp(data->cpyenv[i], "SHLVL", 5) == 0)
    {
        temp = special_case_2(data->cpyenv[i]);
		shlvl = ft_atoi(temp);
		free(temp);
        return (shlvl);
    }
    else
        return (0);
}

void    reduce_shlvl(t_data *data)
{
    int     i;
    char    *temp;
    char	*new_shlvl;
    int     shlvl;

    i = 0;
    while (data->cpyenv[i] && strncmp(data->cpyenv[i], "SHLVL", 5) != 0)
		i++;
    temp = special_case_2(data->cpyenv[i]);
	shlvl = ft_atoi(temp) - 1;
	free(temp);
    new_shlvl = special_case_3(shlvl);
	do_export(data, new_shlvl);
	free(new_shlvl);
}