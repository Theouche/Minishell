/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:54:49 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 11:18:20 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastelem;

	if (!lst || !new)
		return ;
	lastelem = ft_lstlast(*lst);
	if (!lastelem)
		*lst = new;
	else
		lastelem->next = new;
}
