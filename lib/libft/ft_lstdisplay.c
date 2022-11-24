/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:41:35 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:51:50 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdisplay(t_list **stack)
{
	t_list	*buff;

	buff = *stack;
	while (buff != NULL)
	{
		ft_printf("%i\n", *((int *) buff->content));
		buff = buff->next;
	}
}
