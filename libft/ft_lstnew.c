/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:23:46 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/07 16:23:57 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(char *content, int pipe, int red)
{
	t_list	*newelm;

	newelm = malloc(sizeof(t_list));
	if (newelm == NULL)
		return (NULL);
	//newelm->cmd = ft_strdup(content);
	printf("check argument !!!!!!!!!!\n");
	printf("%s\n", content);
	printf("%d\n", pipe);
	printf("%d\n", red);
	newelm->cmd = content;
	newelm->pipe = pipe;
	newelm->redir = red;
	newelm->next = NULL;
	printf("check fonction !!!!!!!!!!\n");
	printf("%s\n", newelm->cmd);
	printf("%d\n", newelm->pipe);
	printf("%d\n", newelm->redir);
	return (newelm);
}
