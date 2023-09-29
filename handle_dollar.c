/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:41:38 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/28 11:42:06 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *add_char(char *str, char c)
{
    char    *new_str;
    int     i;

    new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
    i = 0;
    while (str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    printf("####### new_str vaut : %s\n\n", new_str);
    new_str[i++] = c;
    new_str[i] = 0;
    free(str);
    return(new_str);
}

char    *ft_get_env(t_data *data, char *sch)
{
    int     i;
    int     j;
    int     k;
    char    *find;

    i = 0;
    printf("###########################3ici\n");
    printf("###########################len tab vaut %d\n", len_tab(data->cpyenv));
    while (i < len_tab(data->cpyenv) && ft_strncmp(data->cpyenv[i], sch, ft_strlen(sch)) != 0)
    {
        printf("i vaut %d\n", i);
        i++;
    }
    // si j'arrive au bout de data ?.
    printf("####### i vaut : %d et la len du tab vaut : %d\n\n", i, len_tab(data->cpyenv));
    if (i == len_tab(data->cpyenv))
        return (char_vide());
    find = malloc(sizeof(char) * ft_strlen(data->cpyenv[i]));
    j = ft_strlen(sch) + 1;
    k = 0;
    while (data->cpyenv[i][j])
    {
        find[k] = data->cpyenv[i][j];
        k++;
        j++;
    }
    find[k] = 0;
    return (find);
}

char    *replace_dol(t_data *data, char *str)
{
    char    *ret;
    char    *env;
    int     i;
    int     j;

    ret = malloc(sizeof(char) * ft_strlen(str));
    i = 0;
    while (str[i] != 36)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i++] = 0;
    printf("############# ret vaut %s\n\n", ret);
    env = malloc(sizeof(char) * 100);
    j = 0;
    while (str[i] && (str[i] != ' ' && str[i] != 39 && str[i] != 34))
        env[j++] = str[i++];
    env[j] = 0;
    printf("############# env vaut %s\n\n", env);
    //printf("############# ft_get_env vaut %s\n\n", ft_get_env(data, env));
    ret = ft_strjoin_and_free(ret, ft_get_env(data, env));
    printf("############# final ret vaut %s\n\n", ret);
    if (str[i])
    {
        printf("##########ici\n");
        while (str[i])
        {
            printf("##########je rentre par ici et le char vaut %c\n", str[i]);
            ret = add_char(ret, str[i]);
            printf("###### add_char vaut : %s\n\n", ret);
            i++;
        }
        ret[ft_strlen(str) - ft_strlen(env) + ft_strlen(ft_get_env(data, env))] = 0;
        printf("########## ret a la toute fin vaut %s\n", ret);
    }
    else
        ret[ft_strlen(str) - ft_strlen(env) + ft_strlen(ft_get_env(data, env))] = 0;
    return (ret);
}

int     is_dollar(char *str)
{
    int     i;
    char    fq;

    i = 0;
    fq = 0;
    while (str[i])
    {
        if ((str[i] == 34 || str[i] == 39) && fq != 0)
            fq = 0;
        else if (str[i] == 34 || str[i] == 39)
            fq = str[i];
        else
        {
            if (str[i] == 36 && (fq == 0 || fq == 34) && str[i + 1] && str[i + 1] != ' ' && str[i + 1] != 0)
                return (1);
        }
        i++;
    }
    return (0);
    /*int i;

    i = 0;
    while (str[i]) // 36 = $; 34 = "; 39 = ';
    {
        if (str[i] == 36 && i == 0)
            return (1);
        if (str[i] == 36 && i == 1 && str[i - 1] == 34)
            return (1);
        if (i >= 2 && str[i] == 36 && str[i - 1] == 34 && str[i - 2] != 39)
            return (1);
        if (i >= 2 && str[i] == 36 && str[i - 1] == 39 && str[i - 2] == 34)
            return (1);
        i++;
    }
    return (0);*/
}

char	*handle_dollar(t_data *data, char *prompt)
{
    char    *fin_prompt;

    printf("##########is dollar vaut %d\n", is_dollar(prompt));
    if (is_dollar(prompt) == 1)
        fin_prompt = replace_dol(data, prompt);
    else
        fin_prompt = ft_strdup(prompt);

    printf("#######fin prompt vaut : %s\n\n", fin_prompt);
    return (fin_prompt);
}
