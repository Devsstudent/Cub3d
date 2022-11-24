/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:18:36 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:54:51 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_len_till_nl(s2);
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
	free(s1);
	return (res);
}

char	*gnl_strdup(char *s)
{
	char	*res;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = s[i];
	return (res);
}

size_t	ft_len_till_nl(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\n' && s[size] != '\0')
		size++;
	if (s[size] == '\n')
		size++;
	return (size);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *) s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
