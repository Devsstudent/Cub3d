/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:37:46 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 11:22:48 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*res;
	unsigned char	*yay;
	unsigned char	to_find;
	size_t			i;

	res = NULL;
	i = 0;
	to_find = (unsigned char) c;
	yay = (unsigned char *) s;
	while (i < n)
	{
		if (yay[i] == to_find)
		{
			res = (void *)&yay[i];
			break ;
		}
		i++;
	}
	return (res);
}
