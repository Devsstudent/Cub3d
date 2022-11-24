/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:52:20 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:37:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	int			ret_val;

	ret_val = 0;
	va_start(ap, string);
	ft_loop((char *) string, ap, &ret_val);
	va_end(ap);
	return (ret_val);
}

void	ft_sharp(char x, int *r_v)
{
	printf_putchar('0', r_v);
	printf_putchar(x, r_v);
}
