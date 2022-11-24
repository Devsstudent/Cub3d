/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:01:11 by odessein          #+#    #+#             */
/*   Updated: 2022/05/08 17:52:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	if (write(fd, &c, sizeof(c)))
		return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = (long) n;
	if (n < 0)
	{
		ft_putchar('-', fd);
		temp *= -1;
	}
	if (temp < 10)
	{
		ft_putchar(temp + 48, fd);
		return ;
	}
	ft_putnbr_fd(temp / 10, fd);
	ft_putchar((temp % 10) + 48, fd);
}
