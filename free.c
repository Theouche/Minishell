/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:19:32 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/08 11:20:06 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void    free_struct(t_data *data, char *new_cmd)
{
    if (new_cmd)
        free(new_cmd);
}*/

void	end_turn(t_data *data, char *prompt)
{
    if (prompt)
        free(prompt);
    if (data->fsplit)
        ft_free_split(data->fsplit);
    if (data->cmd)
        ft_free_split(data->cmd);
    if (data->prompt)
        free(data->prompt);
}

void	end_prog(t_data *data, char *prompt)
{
    end_turn(data, prompt);
    //printf("################## ok\n");
    if (data->pwd)
        free(data->pwd);
    if (data->path)
        free(data->path);
    if (data->home)
        free(data->home);
    if (data->cpyenv)
        ft_free_split(data->cpyenv);
    //printf("################## ok2\n");
    free(data);
    //printf("################## ok5\n");
}
