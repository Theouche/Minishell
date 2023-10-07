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

t_list	*ft_lstnew(void *content)
{
	t_list	*newelm;

	newelm = malloc(sizeof(t_list));
	if (newelm == NULL)
		return (NULL);
	newelm->content = content;
	newelm->next = NULL;
	return (newelm);
}
