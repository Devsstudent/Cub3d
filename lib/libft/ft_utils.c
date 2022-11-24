/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:58:50 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:47:26 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_power(long number, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (number);
	else
		return (number * ft_power(number, power - 1));
}

void	printf_putchar(char c, int *ret_val)
{
	if (write(STDOUT_FILENO, &c, 1))
		(*ret_val)++;
	else
		(*ret_val) = -1;
}

void	ft_putnbr_addr(unsigned long nb, int *ret_val)
{
	if (nb < 16)
	{
		printf_putchar(BASE_L[nb], ret_val);
		return ;
	}
	ft_putnbr_addr(nb / 16, ret_val);
	printf_putchar(BASE_L[nb % 16], ret_val);
	if (*ret_val == -1)
		return ;
}

t_bool	ft_check_minus(char *str)
{
	while (*str && !ft_check_end(*str))
	{
		if (*str == '-')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_bool	ft_check_neg_sign(char *str)
{
	while (*str && !ft_check_end(*str))
	{
		if (*str == '0' && !ft_is_digit(*(str - 1)))
			return (FALSE);
		if (*str == '.')
			return (FALSE);
		str++;
	}
	return (TRUE);
}
