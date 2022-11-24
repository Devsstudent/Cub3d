/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:00 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 13:24:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	size++;
	return (size);
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
	new = ft_lstnew(test);
	new2 = ft_lstnew(test2);
	new3 = ft_lstnew(test2);
	new5 = ft_lstnew(test2);
	new4 = ft_lstnew(test2);
	ft_lstadd_front(&new, new2);
	ft_lstadd_front(&new2, new3);
	ft_lstadd_front(&new3, new4);
	ft_lstadd_front(&new4, new5);
	printf("%i", ft_lstsize(new4));
}
*/
