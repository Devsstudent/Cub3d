/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:17:53 by odessein          #+#    #+#             */
/*   Updated: 2022/05/09 11:20:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	char	*s_bis;

	res = NULL;
	s_bis = (char *) s;
	while (*s_bis)
	{
		if (*s_bis == (char) c)
		{
			res = s_bis;
			break ;
		}
		s_bis++;
	}
	if (c == 0)
		res = s_bis;
	return (res);
}
