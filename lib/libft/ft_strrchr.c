/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:38:38 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 11:24:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*res;

	res = NULL;
	size = ft_strlen(s);
	while (size > -1)
	{
		if (s[size] == (char) c)
		{
			res = (char *) &s[size];
			break ;
		}
		size--;
	}
	return (res);
}
