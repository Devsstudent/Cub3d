/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:40:08 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 10:35:39 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
{
	char	*test;
	char	*test2;
	test = "test";
	test2 = "aja";
	t_list *new;
	t_list *new3;
	t_list *new4;
	t_list *new5;
	t_list *new2;
	new = ft_lstnew(test2);
	new2 = ft_lstnew(test);
	new3 = ft_lstnew(test);
	new5 = ft_lstnew(test);
	new4 = ft_lstnew(test);
	ft_lstadd_front(&new, new2);
	ft_lstadd_front(&new2, new3);
	ft_lstadd_front(&new3, new4);
	ft_lstadd_front(&new4, new5);
	t_list *store;
	store = ft_lstlast(new5);
	printf("%s", (char *)store->content);
}
*/
