/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:57:48 by odessein          #+#    #+#             */
/*   Updated: 2022/05/13 19:20:48 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size != 0 && nmemb > SIZE_MAX / size)
		ret = NULL;
	else
	{
		ret = malloc(nmemb * size);
		if (!ret)
			return (NULL);
		ft_bzero(ret, size * nmemb);
	}
	return (ret);
}
