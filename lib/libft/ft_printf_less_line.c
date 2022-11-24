/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_less_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:36:39 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:46:57 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_bool	ft_space_at_start(char *str, int *i, t_useful *sign, int *ret_val)
{
	if (str[*i] == ' ' && str[*(i) + 1] != '0' && !(*sign).need_neg)
	{
		while (str[(*i) + 1] == ' ')
			(*i)++;
		printf_putchar(' ', ret_val);
		if (*ret_val == -1)
			return (TRUE);
	}
	return (FALSE);
}

int	ft_space(char *str, int *i, int *ret_val, int size)
{
	if (ft_is_digit(str[*i]) && !ft_check_minus(str) && str[*i] != '0'
		&& str[(*i) - 1] != '-' && !ft_is_digit(str[(*i) - 1]))
		*i = ft_disp_space(str, size, *i, ret_val);
	return (*i);
}
