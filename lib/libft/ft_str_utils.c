/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:50:11 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:50:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_bool	ft_check_addsign(char *str)
{
	while (*(str))
	{
		if (*str == '+')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_bool	ft_check_dieze(char *str)
{
	while (*str && (*str == '%' || !ft_check_end(*str)))
	{
		if (*str == '#')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_bool	ft_check_space(char *str)
{
	while (*str && (*str == '%' || !ft_check_end(*str)))
	{
		if (*str != '0' && ft_is_digit(*str) && *(str - 1) != '.'
			&& !ft_is_digit(*(str - 1)))
		{
			return (TRUE);
		}
		str++;
	}
	return (FALSE);
}

int	ft_need_sign(char *str, int size, t_useful *need_add, int *ret_val)
{
	if (ft_check_addsign(str) && !((*need_add).need_neg))
	{
		printf_putchar('+', ret_val);
		size++;
		(*need_add).need_add = TRUE;
	}
	if ((*need_add).need_neg)
	{
		(*need_add).need_neg = FALSE;
		(*need_add).prec = TRUE;
		printf_putchar('-', ret_val);
	}
	return (size);
}

t_bool	ft_is_digit(char c)
{
	if (c < 58 && c > 47)
		return (TRUE);
	return (FALSE);
}
