/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:52:52 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:30:19 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_power_static(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else if (power < 2)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}

static int	ft_size_and_tools(long long *temp, int *buff_size)
{
	int		size;
	long	buff_temp;

	size = 1;
	*buff_size = 1;
	if (*temp < 0)
	{
		size++;
		*temp = *temp * -1;
	}
	buff_temp = *temp;
	while (buff_temp > 9)
	{
		buff_temp = buff_temp / 10;
		size++;
		*buff_size = *buff_size + 1;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	int			i;
	int			buff_size;
	char		*res;
	long long	temp;

	i = 0;
	temp = (long long) n;
	size = ft_size_and_tools(&temp, &buff_size);
	res = (char *) malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (NULL);
	if (size - buff_size > 0)
		res[i++] = '-';
	while (i < size)
	{
		res[i] = temp / ft_power_static(10, buff_size - 1) + 48;
		temp = temp % ft_power(10, buff_size - 1);
		i++;
		buff_size--;
	}
	res[i] = '\0';
	return (res);
}
