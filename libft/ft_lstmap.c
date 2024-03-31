/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhatia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:39:07 by dbhatia           #+#    #+#             */
/*   Updated: 2023/09/21 14:39:09 by dbhatia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*s;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		s = ft_lstnew(f(lst->content));
		if (!s)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, s);
		lst = lst->next;
	}
	return (new_lst);
}
