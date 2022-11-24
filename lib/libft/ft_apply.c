/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:47:13 by odessein          #+#    #+#             */
/*   Updated: 2022/06/02 15:33:04 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_apply_rules_before(char *str, int size, t_useful *sign, int *r_v)
{
	int	i;

	i = 0;
	while (!ft_check_end(str[++i]))
	{
		if (ft_space_at_start(str, &i, sign, r_v))
			return ;
		i = ft_space(str, &i, r_v, size);
		if (str[i] == '0' && !ft_check_end(str[i + 1]))
		{
			if (ft_check_precision_or_not(str) && ft_is_digit(str[i + 1]))
			{
				if ((*sign).prec || (sign->need_neg))
					ft_disp_space_neg(str, size, ft_atoi(&str[i + 1]), r_v);
				else
					i = ft_disp_space(str, size, i + 1, r_v) + 1;
				break ;
			}
			size = ft_need_sign(str, size, sign, r_v);
			if (ft_is_digit(str[i + 1]))
				i = ft_disp_zero(str, size, i + 1, r_v);
		}
		if (str[i] == '.' || ft_check_end(str[i]))
			return ;
	}
}

void	ft_apply_minus_sign(char *str, int size, int *ret_val, t_useful *neg)
{
	int	i;

	i = 1;
	if (ft_check_dieze(str))
		size++;
	while (!(ft_check_end(str[i])))
	{
		if (str[i] == '-' && ft_is_digit(str[i + 1]))
		{
			if ((*neg).prec || (*neg).need_neg)
				ft_disp_space_neg(str, size, ft_atoi(&str[i + 1]), ret_val);
			else
				ft_disp_space(str, size, i + 1, ret_val);
			if (*ret_val == -1)
				return ;
		}
		i++;
	}
}

void	ft_precision(char *str, int size, t_useful *add_sign, int *ret_val)
{
	int		nb_of_zero;
	int		i;

	i = 0;
	while (!ft_check_end(str[++i]))
	{
		if (str[i] == '.')
		{
			size = ft_need_sign(str, size, add_sign, ret_val);
			if ((*add_sign).prec)
				size--;
			if (ft_is_digit(str[i + 1]))
			{
				nb_of_zero = ft_atoi(&str[i + 1]) - size;
				while (nb_of_zero-- > 0)
				{
					printf_putchar('0', ret_val);
					if (*ret_val == -1)
						return ;
				}
				return ;
			}
		}
	}
}

int	ft_disp_zero(char *str, int size, int index, int *ret_val)
{
	int		nb_of_zero;
	int		index_cursor;

	index_cursor = index;
	while (ft_is_digit(str[index_cursor]))
		index_cursor++;
	if (size == 0)
		return (index_cursor);
	nb_of_zero = ft_atoi(&str[index]) - size;
	nb_of_zero = ft_check_precision(str, nb_of_zero, size);
	while (nb_of_zero > 0)
	{
		printf_putchar('0', ret_val);
		if (*ret_val == -1)
			return (ft_strlen(str) - 1);
		nb_of_zero--;
	}
	return (index_cursor);
}

int	ft_disp_space(char *str, int size, int index, int *ret_val)
{
	int		nb_of_space;

	nb_of_space = ft_atoi(&str[index]) - size;
	nb_of_space = ft_check_precision(str, nb_of_space, size);
	while (nb_of_space > 0)
	{
		printf_putchar(' ', ret_val);
		if (*ret_val == -1)
			return (ft_strlen(str) - 1);
		nb_of_space--;
	}
	while (ft_is_digit(str[index]))
		index++;
	return (index);
}
