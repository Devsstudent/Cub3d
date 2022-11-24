/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:06:59 by odessein          #+#    #+#             */
/*   Updated: 2022/05/12 16:18:40 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst->next != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	(*f)(lst->content);
}

/*
void	ft_del(void *content)
{
	*((char *) content) = 'a';
}

int	main(void)
{
	char	test[] = "test";
	char	test2[] = "aja";

	void (*ft)(void *) = &ft_del;

	t_list *new;
	t_list *new3;
	t_list *new4;
	t_list *new5;
	t_list *new2;

	new = ft_lstnew(test);
	new2 = ft_lstnew(test);
	new3 = ft_lstnew(test);
	new5 = ft_lstnew(test2);
	new4 = ft_lstnew(test);

	ft_lstadd_back(&new, new2);
	ft_lstadd_back(&new2, new3);
	ft_lstadd_back(&new3, new4);
	ft_lstadd_back(&new4, new5);
	ft_lstiter(new3, ft);
	printf("%s", (char *) new->content);
}*/
