/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:08:06 by odessein          #+#    #+#             */
/*   Updated: 2022/05/12 16:21:32 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;
	size_t	dest_src;

	i = 0;
	j = 0;
	i = ft_strlen(dst);
	dest_size = i;
	dest_src = ft_strlen(src);
	if (dest_size >= size)
		return (size + dest_src);
	while (j < size - 1 - dest_size && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_src + dest_size);
}

/*
#include <bsd/string.h>

int	main(void)
{
	char *dest;
 	memset(dest, 'r', 15);
 	char yay[] = "lorem ipsum dolor sit amet";
	printf("%li", ft_strlcat(dest, yay, 5));
	printf("%s", test);
	
}
*/
