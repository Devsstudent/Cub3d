/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:56:06 by odessein          #+#    #+#             */
/*   Updated: 2022/05/13 15:24:30 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_in_trim(char to_test, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (to_test == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_calc_size(char *s1, char const *set)
{
	int	i;
	int	size;
	int	j;

	size = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_is_in_trim(s1[i], set))
		i++;
	while (ft_is_in_trim(s1[j], set))
		j--;
	while (i <= j)
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		size;
	int		i;
	int		j;
	int		k;

	k = 0;
	size = ft_calc_size((char *) s1, set);
	res = malloc(sizeof(*res) * size + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_is_in_trim(s1[i], set))
		i++;
	while (j >= 0 && ft_is_in_trim(s1[j], set))
		j--;
	if (j < 0)
		res[0] = '\0';
	while (k < size)
		res[k++] = s1[i++];
	res[k] = '\0';
	return (res);
}
