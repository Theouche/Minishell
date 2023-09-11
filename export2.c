/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:23:48 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/07 10:23:50 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_export_no_name(t_data *data, char *exp)
{
    int     i;
    char    **envcpy_2;

    i = 0;
    while (data->cpyenv[i])
        i++;
    envcpy_2 = malloc(sizeof(char *) * (i + 3));
    i = 0;
    while (data->cpyenv[i])
    {
        envcpy_2[i] = ft_strdup(data->cpyenv[i]);
        i++;
    }
    printf("ok2\n");
    envcpy_2[i++] = ft_strdup(exp);
    envcpy_2[i] = 0;
    ft_free_split(data->cpyenv);
    data->cpyenv = malloc(sizeof(char *) * (i + 1));
    i = -1;
    while (envcpy_2[++i])
        data->cpyenv[i] = ft_strdup(envcpy_2[i]);
    data->cpyenv[i] = 0;
    ft_free_split(envcpy_2);
    return ;
}
