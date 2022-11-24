/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:28:22 by odessein          #+#    #+#             */
/*   Updated: 2022/06/04 22:42:59 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen_special(char *s, char *pattern)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (!ft_check_end(pattern[++i]))
	{
		if (ft_is_digit(pattern[i]) && pattern[i - 1] != '-' && !s)
		{
			return (6);
		}
		if (pattern[i] == '.' && pattern[i + 1] == 's')
			return (0);
		if (pattern[i] == '.' && ft_is_digit(pattern[i + 1]))
		{
			size = ft_atoi(&pattern[i + 1]);
			return (size);
		}
	}
	while (s && s[size] != '\0')
		size++;
	return (size);
}

int	ft_calc_number_size(unsigned long value, char *str)
{
	long	val;
	int		size;

	val = value;
	size = 0;
	if (val < 0)
	{
		val = val * (-1);
		size++;
	}
	if (val == 0 && !ft_check_novalue(str, (int) value))
		return (1);
	while (val > 0)
	{
		val = val / 10;
		size++;
	}
	return (size);
}

int	ft_calc_hexa_size(char *str, unsigned long value)
{
	long		val;
	int			size;
	long		index;

	if (ft_check_novalue(str, value))
		return (0);
	index = ft_calc_number_size((unsigned long) value, str);
	val = value;
	size = 0;
	if (val == 0)
		return (size + 1);
	while (val % ft_power(16, index) == val)
		index--;
	while (index >= 0)
	{
		val = val % ft_power(16, index);
		size++;
		index--;
	}
	if (ft_check_zero_or_space(str) && ft_check_dieze(str))
		size = size + 2;
	return (size);
}

int	ft_check_precision(char *str, int expected_space, int size)
{
	int	i;
	int	nb_of_zero;
	int	res;

	i = 1;
	res = expected_space;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == '.' && ft_is_digit(str[i + 1]))
		{
			nb_of_zero = ft_atoi(&str[i + 1]) - size;
			if (nb_of_zero < 0)
				nb_of_zero = 0;
			res = expected_space - nb_of_zero;
		}
		i++;
	}
	if (str[i] == 's')
		return (expected_space);
	return (res);
}
