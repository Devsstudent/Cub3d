/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:30:00 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:37:39 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnstr(char *str, int size, int *ret_val)
{
	int	i;

	i = 0;
	if (!str && size > 5)
		ft_putnstr("(null)", 6, ret_val);
	else
	{
		while (i < size && str[i] != '\0')
		{
			printf_putchar(str[i], ret_val);
			if (*ret_val == -1)
				return ;
			i++;
		}
	}
}
