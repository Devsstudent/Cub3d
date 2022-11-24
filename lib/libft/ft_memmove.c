/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:01:03 by odessein          #+#    #+#             */
/*   Updated: 2022/05/12 16:23:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dest && !src)
		return (NULL);
	temp1 = (unsigned char *) dest;
	temp2 = (unsigned char *) src;
	i = -1;
	if (dest > src)
	{
		while (n > 0)
		{
			temp1[n - 1] = temp2[n - 1];
			n--;
		}
	}
	else
		while ((size_t)(++i) < n)
			temp1[i] = temp2[i];
	return (dest);
}
