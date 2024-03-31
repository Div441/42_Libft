/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhatia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:28:15 by dbhatia           #+#    #+#             */
/*   Updated: 2023/09/21 14:28:27 by dbhatia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (! lst || ! new)
		return ;
	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = &*new;
	}
	else
		*lst = new;
}
