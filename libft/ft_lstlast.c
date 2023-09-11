/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:59 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/09 10:52:55 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	write(1, "deb last\n", 9);
	if (!lst)
	{
		write(1, "fin lastNN\n", 11);
		return (NULL);
	}
	while (lst->next)
		lst = lst->next;
	write(1, "fin last\n", 9);
	return (lst);
}
