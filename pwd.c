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

int     apply_pwd(t_data *data)
{
	//int	i;
	int	j;
	char	*pwd;


	(void)data;
	//i = 0;
	//while (strncmp(env[i], "PWD", 3) != 0)
	//	i++;
	/*j = 4;
	while (env[i][j])
	{
		ft_printf("%c", env[i][j]);
		j++;	
	}*/

	// 2eme forme.
	pwd = getcwd(NULL, 0);
	j = -1;
	while (pwd[++j])
		ft_printf("%c", pwd[j]);
	ft_printf("\n");
	return (2);
}
