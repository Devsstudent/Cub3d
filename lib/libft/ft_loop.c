/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:47:47 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:49:29 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline char	*ft_brows_1(char *str, int *ret_val)
{
	int	i;

	i = 0;
	if (str[1] == '%')
	{
		printf_putchar('%', ret_val);
		if (*ret_val == -1)
			return (str + ft_strlen(str) - 1);
		return (str + 1);
	}
	while (str[i] && (str[i] == '%' || !ft_check_end(str[i])))
		i++;
	if (i == (int) ft_strlen(str) && !ft_check_end(str[i]))
	{
		i = 0;
		while (str[i] && (str[i] == '%' || !ft_check_end(str[i])))
			printf_putchar(str[i++], ret_val);
		*ret_val = -1;
		return (0);
	}
	return (0);
}

void	ft_loop(char *string, va_list ap, int *ret_val)
{
	t_storage	handle;

	while (*string)
	{
		handle.content = string;
		if (*string == '%')
			string = ft_brows((char *) handle.content, ap, ret_val);
		else
		{
			printf_putchar(*string, ret_val);
			if (*ret_val == -1)
				return ;
		}
		string++;
	}
}

t_bool	ft_check_end(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p' || c == 's')
		return (TRUE);
	else if (c == 'c' || c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	return (FALSE);
}

char	*ft_brows(char *str, va_list ap, int *ret_val)
{
	int		i;
	char	*store;
	t_bool	not_end;

	i = 0;
	not_end = FALSE;
	store = ft_brows_1(str, ret_val);
	if (store != 0)
		return (store);
	while (str[++i] != '\0' && !not_end)
	{
		if (str[i] == 'i' || str[i] == 'd')
			ft_manage_int(str, va_arg(ap, int), ret_val, &not_end);
		else if (str[i] == 'x' || str[i] == 'X')
			ft_manage_hexa(str, va_arg(ap, unsigned), ret_val, &not_end);
		else if (str[i] == 'u')
			ft_manage_unsigned(str, va_arg(ap, unsigned), ret_val, &not_end);
		else if (str[i] == 's')
			ft_manage_string(str, va_arg(ap, char *), ret_val, &not_end);
		else if (str[i] == 'c')
			ft_manage_char(str, va_arg(ap, int), ret_val, &not_end);
		else if (str[i] == 'p')
			ft_manage_addr(str, va_arg(ap, void *), ret_val, &not_end);
	}
	return (str + (--i));
}

t_bool	ft_check_novalue(char *str, unsigned int val)
{
	while (*str)
	{
		if (*str == '.' && (!ft_is_digit(*(str + 1)) || *(str + 1) == '0')
			&& val == 0)
			return (TRUE);
		str++;
	}
	return (FALSE);
}
