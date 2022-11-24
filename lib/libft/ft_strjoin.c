/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:54:13 by odessein          #+#    #+#             */
/*   Updated: 2022/05/07 11:54:15 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	res = (char *) malloc(sizeof(*res) * (total_len + 1));
	if (!res)
		return (NULL);
	while ((size_t)(++i) < total_len)
	{
		if ((size_t) i == ft_strlen(s1))
			j = -1;
		if ((size_t) i < ft_strlen(s1))
			res[i] = s1[++j];
		else
			res[i] = s2[++j];
	}
	res[i] = '\0';
	return (res);
}
