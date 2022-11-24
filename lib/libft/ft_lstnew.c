/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:51:08 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 12:17:24 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*
int	main(void)
{
	t_list	*new;
	void	*content;
	char	*test;
	test = "test";

	content = (void *) test;
	new = ft_lstnew(content);
	printf("%s", (char *) new->content);
}
*/
