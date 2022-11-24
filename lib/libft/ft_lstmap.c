/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:27 by odessein          #+#    #+#             */
/*   Updated: 2022/05/12 16:19:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**head;
	t_list	*new_ele;

	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		ft_lstdelone(new_list, del);
	head = &new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		new_ele = ft_lstnew((*f)(lst->content));
		if (!new_ele)
			ft_lstclear(head, del);
		ft_lstadd_back(&new_list, new_ele);
		lst = lst->next;
	}
	return (*head);
}
