/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:07:39 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/07 14:07:40 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_unset_find(t_data *data, char *unset)
{
    int     i;
    char    **envcpy_2;

    i = 0;
    while (data->cpyenv[i])
        i++;
    envcpy_2 = malloc(sizeof(char *) * (i));
    i = 0;
    while (data->cpyenv[i])
    {
        if (ft_strncmp(data->cpyenv[i], unset, ft_strlen(unset)) != 0)
            envcpy_2[i] = ft_strdup(data->cpyenv[i]);
        i++;
    }
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

void    do_unset(t_data *data, char *unset)
{
    int i;
    int len;

    len = ft_strlen(unset);
    printf("verif, unset est : %s, sa longueur vaut %d\n", unset, len);
    i = 0;
    while (data->cpyenv[i])
    {
        //printf("ok\n");
        if (ft_strncmp(data->cpyenv[i], unset, len) == 0)
        {
            printf("ok_3\n");
            do_unset_find(data, unset);
            return ;
        }
        i++;
    }
    return ;
}

int check_arg_unset(char *exp)
{
    int i;

    i = 0;
    while (exp[i])
    {
        if (ft_isalpha(exp[i]) != 1)
            return (0);
        i++;
    }
    return (1);
}

void    ft_unset(t_data *data, char **unset)
{
    int i;

    i = 0;
    while (unset[++i])
    {
        if (check_arg_unset(unset[i]) == 1)
            do_unset(data, unset[i]);
        else
            ft_printf("this arg : %s is wrong\n", unset[i]);
    }
}

int apply_unset(t_data *data)
{
    int     i;
    char    **cmd;
    char    **clean_cmd;

    i = 0;
    cmd = ft_split(data->fsplit[0], ' ');
    while (cmd[i])
        i++;
    clean_cmd = malloc(sizeof(char *) * i + 1);
    clean_cmd[0] = ft_strdup(cmd[0]);
    i = 1;
    while (cmd[i])
    {
        if (is_quote(cmd[i]) == 1)
        {
            //printf("with quote %d\n\n", is_quote(cmd[i]));
            clean_cmd[i] = remove_quote(cmd[i]);
            //printf("c'est remove quote qui deconne ? %s\n\n", clean_cmd[i]);
        }
        else
            clean_cmd[i] = ft_strdup(cmd[i]);
        i++;
    }
    clean_cmd[i] = 0;
    ft_unset(data, clean_cmd);
    return (5);
}
