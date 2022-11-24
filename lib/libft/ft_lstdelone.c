/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:25:55 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 10:37:02 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*buff;

	buff = lst;
	lst = lst->next;
	(*del)(buff->content);
	free(buff);
}

/*
int	main(void)
{
	t_list	*new;
	char *test;
	test = "okok";
	void	(*ft_ptr)(void *) = &ft_del;

	new = ft_lstnew(test);
	printf("%s", (char *)new->content);
	ft_lstdelone(new, ft_ptr);
}
*/
