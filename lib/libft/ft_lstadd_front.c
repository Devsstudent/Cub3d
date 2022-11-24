/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:08:57 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 13:07:07 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	char	*test;
	char	*test2;
	char	*test3;

	test = "test";
	test2 = "aja";
	test3 = "bien";

	t_list *new;
	t_list *new2;
	t_list *new3;

	new = ft_lstnew(test);
	new2 = ft_lstnew(test2);
	new3 = ft_lstnew(test3);

	ft_lstadd_front(&new, new2);
	ft_lstadd_front(&new2, new3);
	printf("%s", (char *)new->next);
}
*/
