/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:46:07 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/04 18:26:32 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	apply_pwd(t_data *data)
{
	int		j;
	char	*pwd;

	(void)data;
	pwd = getcwd(NULL, 0);
	j = -1;
	while (pwd[++j])
		ft_printf("%c", pwd[j]);
	ft_printf("\n");
	free(pwd);
	return (2);
}
