/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:03:17 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/05 13:03:39 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    do_export(t_data *data, char *exp)
{
    int i;
    int len;
    char    *name;

    i = 0;
    while (exp[i] != '=')
        i++;
    len = i;
    name = ft_strndup_ms(exp, len);
   // printf("verif, name est : %s\n", name);
    i = 0;
    while (data->cpyenv[i])
    {
        //printf("ok\n");
        if (ft_strncmp(data->cpyenv[i], name, len) == 0)
        {
            data->cpyenv[i] = ft_strdup(exp);
            return ;
        }
        i++;
    }
    //printf("ok\n");
    do_export_no_name(data, exp);
    return ;
}

int check_arg_export(char *exp)
{
    int i;
    int aft_spac;

    i = 0;
    aft_spac = 0;
    if (exp[0] == '=')
        return (0);
    while (exp[i])
    {
        if (exp[i] == '=')
            aft_spac = 1;
        if ((exp[i] == 34 || exp[i] == 39) && aft_spac == 0)
            return (0);
        if (ft_isalnum(exp[i]) == 0 && exp[i] != '_' && aft_spac == 0)
            return (0);
        i++;
    }
    return (1);
}

void    ft_export(t_data *data, char **export)
{
    int i;

    i = 0;
    while (export[++i])
    {
        if (check_arg_export(export[i]) == 1)
            do_export(data, export[i]);
        else
            ft_printf("this arg : %s is wrong\n", export[i]);
    }
}

char    *remove_quote(char *cmd)
{
    char    *wq;
    int     i;
    int     j;
    char    fq;

    i = 0;
    j = 0;
    wq = malloc(sizeof(char) * ft_strlen(cmd));
    while (cmd[i])
    {
        if (cmd[i] == 34 || cmd[i] == 39)
		{
			fq = cmd[i++];
			while (cmd[i] && cmd[i] != fq)
                wq[j++] = cmd[i++];
			i++;
		}
        else
            wq[j++] = cmd[i++];
    }
    wq[j] = 0;
    return (wq);
}

int	apply_export(t_data *data, char **cmd)
{
    int     i;
    //char    **cmd;
    char    **clean_cmd;

    //printf("begin export \n\n");
    i = 0;
    //cmd = ft_split(data->fsplit[0], ' ');
    while (cmd[i])
        i++;
    //printf("split fait \n\n");
    clean_cmd = malloc(sizeof(char *) * i + 1);
    clean_cmd[0] = ft_strdup(cmd[0]);
    //printf("dup %s\n\n", clean_cmd[0]);
    i = 1;
    while (cmd[i])
    {
        //printf("%s\n", cmd[i]);
        if (is_quote(cmd[i]) == 1)
        {
            //printf("with quote %d\n\n", is_quote(cmd[i]));
            clean_cmd[i] = remove_quote(cmd[i]);
            //printf("c'est remove quote qui deconne ? %s\n\n", clean_cmd[i]);
        }
        else
        {
            //printf("no quote\n\n");
            clean_cmd[i] = ft_strdup(cmd[i]);
            //printf("c'est dup qui deconne ? %s\n\n", clean_cmd[i]);
        }
        //printf("la %d eme clean cmd vaut %s\n", i, clean_cmd[i]);
        i++;
    }
    clean_cmd[i] = 0;
    ft_export(data, clean_cmd);
    return (4);
}
