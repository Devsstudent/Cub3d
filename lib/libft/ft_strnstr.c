/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:16:18 by odessein          #+#    #+#             */
/*   Updated: 2022/05/11 09:13:13 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	if (ft_strlen(little) <= 0)
		return ((char *) big);
	i = -1;
	while (big[++i] && (size_t) i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && (size_t) i < len)
			{
				if (little[j] == '\0')
					return ((char *) &big[i - j]);
				j++;
				i++;
			}
			if (little[j] == '\0')
				return ((char *) &big[i - j]);
			else
				i = i - j;
		}
	}
	return (NULL);
}

/*
#include <bsd/string.h>
int	main(void)
{
	char test[30] = "lorem ipsum dolor sit amet";
	char *test1 = (char *) "";
	char *res;

	res = ft_strnstr(test, "", 0);
	printf("%s", res);
}*/
