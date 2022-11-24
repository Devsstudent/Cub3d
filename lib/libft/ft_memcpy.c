/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:33:16 by odessein          #+#    #+#             */
/*   Updated: 2022/05/12 16:19:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
		printf("%p, %p\n", (void *) src[i], (void *)  dest[j]);
		if ((void *) src[i] == (void *) dest[j])
			return (1);
static int	ft_check_overlap(char *src, char *dest, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (src[i] == dest[j])
			return (1);
		i++;
	}
	return (0);
}
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s_src;
	char	*s_dest;
	char	buff;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s_src = (char *) src;
	s_dest = (char *) dest;
	while (i < n)
	{
		buff = s_src[i];
		s_dest[i] = buff;
		i++;
	}
	return (s_dest);
}
