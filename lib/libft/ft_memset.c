/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:37:22 by odessein          #+#    #+#             */
/*   Updated: 2022/05/10 11:16:22 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*test;
	size_t	i;

	i = 0;
	test = (char *) s;
	while (i < n)
	{
		test[i] = c;
		i++;
	}
	return (test);
}
