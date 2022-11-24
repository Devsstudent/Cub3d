/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:43:18 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:47:34 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_strndup(char *s, size_t n)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (n > len)
		n = len;
	res = (char *) malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0' && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**ft_less_line(char *s, char c, int *i, char **res)
{
	size_t	j;
	int		k;
	char	*temp;

	k = 0;
	while (s[++(*i)] != '\0')
	{
		j = 0;
		if (s[(*i)] != c && s[(*i)])
		{
			temp = &s[*i];
			while (s[(*i)] != c && s[(*i)] != '\0')
			{
				(*i)++;
				j++;
			}
			res[k] = ft_strndup(temp, j);
			k++;
			(*i)--;
		}
	}
	res[k] = NULL;
	return (res);
}

char	**ft_count_word(char *s, char c)
{
	char	**res;
	int		size;

	size = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			size++;
		}
		while (*s && *s == c)
			s++;
	}
	res = (char **) malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	res = NULL;
	i = -1;
	if (!s)
		return (res);
	res = ft_count_word((char *) s, c);
	res = ft_less_line((char *) s, c, &i, res);
	return (res);
}
