/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:34:28 by odessein          #+#    #+#             */
/*   Updated: 2022/05/13 21:16:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

inline static int	ft_malloc_size(char *s, int start, size_t len, char **ret)
{
	int		size;
	int		buff;
	int		i;

	size = 0;
	i = 0;
	buff = start;
	if (buff == 0 && ft_strlen(s) < len)
		size++;
	while (i < (int) len && s[buff] != '\0')
	{
		size++;
		i++;
		buff++;
	}
	if (i == size)
		size++;
	if (start == (int) len)
		size = len + 1;
	*ret = malloc(sizeof(char) * size);
	if (!(*ret))
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	i = start;
	j = 0;
	if (!ft_malloc_size((char *) s, (int) start, len, &res))
		return (NULL);
	while (j < len && s[i] != '\0')
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
