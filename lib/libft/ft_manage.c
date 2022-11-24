/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:58:51 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:49:04 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_manage_int(char *str, int value, int *ret_val, t_bool *not_end)
{
	int			size;
	t_useful	need_add;

	*not_end = TRUE;
	ft_init_struc(&need_add);
	if (value < 0)
		need_add.need_neg = TRUE;
	size = ft_calc_number_size((unsigned long) value, str);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &need_add, ret_val);
	if (ft_check_neg_sign(str) && need_add.need_neg)
		printf_putchar('-', ret_val);
	if (ft_check_addsign(str) && (!need_add.need_neg && !need_add.need_add))
	{
		printf_putchar('+', ret_val);
		if (*ret_val == -1)
			return ;
		size++;
	}
	if (!ft_check_novalue(str, (unsigned int) value))
		printf_putnbr((long) value, ret_val);
	if (*ret_val == -1)
		return ;
	ft_apply_minus_sign(str, size, ret_val, &need_add);
}

void	ft_manage_hexa(char *str, unsigned int val, int *r_v, t_bool *not_end)
{
	int			size;
	char		u_or_l;
	int			i;
	t_useful	need_add;

	ft_manage_hexa_v1(&i, &need_add, not_end, str);
	if (str[i] == '\0')
		return ;
	u_or_l = str[i];
	size = ft_calc_hexa_size(str, (unsigned long) val);
	if (ft_check_dieze(str) && val != 0 && ft_check_space(str))
		ft_apply_rules_before(str, size, &need_add, r_v);
	if (ft_check_dieze(str) && val != 0)
		ft_sharp(u_or_l, r_v);
	if (ft_check_dieze(str) && val != 0 && !ft_check_space(str))
		ft_apply_rules_before(str, size, &need_add, r_v);
	if (!ft_check_dieze(str))
		ft_apply_rules_before(str, size, &need_add, r_v);
	ft_precision(str, size, &need_add, r_v);
	if (u_or_l == 'X' && !ft_check_novalue(str, val))
		ft_putnbr_hexa_x(val, r_v);
	else if (u_or_l == 'x' && !ft_check_novalue(str, val))
		ft_putnbr_hexa(val, r_v);
	ft_apply_minus_sign(str, size, r_v, &need_add);
}

void	ft_manage_string(char *str, char *value, int *ret_val, t_bool *not_end)
{
	int			size;
	t_useful	need_add;

	*not_end = TRUE;
	ft_init_struc(&need_add);
	size = ft_strlen_special(value, str);
	if (value && size > (int) ft_strlen(value))
		size = ft_strlen(value);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	if (!value)
	{
		if (str[1] == 's')
		{
			ft_putnstr("(null)", 6, ret_val);
			return ;
		}
		if (size < 6 && ft_check_precision_or_not(str))
			return ;
		ft_putnstr("(null)", 6, ret_val);
		return ;
	}
	ft_putnstr(value, size, ret_val);
	ft_apply_minus_sign(str, size, ret_val, &need_add);
}

void	ft_manage_addr(char *str, void *addr, int *ret_val, t_bool *not_end)
{
	unsigned long	addr_conv;
	int				size;
	t_useful		need_add;

	*not_end = TRUE;
	ft_init_struc(&need_add);
	if (!addr)
	{	
		size = 5;
		ft_apply_rules_before(str, size, &need_add, ret_val);
		ft_putnstr("(nil)", 5, ret_val);
		return ;
	}
	addr_conv = (unsigned long) addr;
	size = ft_calc_hexa_size(str, addr_conv) + 2;
	if ((long) addr == -1)
		size = 16;
	ft_apply_rules_before(str, size, &need_add, ret_val);
	printf_putchar('0', ret_val);
	printf_putchar('x', ret_val);
	ft_putnbr_addr(addr_conv, ret_val);
	ft_apply_minus_sign(str, size, ret_val, &need_add);
}

void	ft_manage_char(char *str, char c, int *ret_val, t_bool *not_end)
{
	t_useful	need_add;

	*not_end = TRUE;
	ft_init_struc(&need_add);
	ft_apply_rules_before(str, 1, &need_add, ret_val);
	printf_putchar(c, ret_val);
	ft_apply_minus_sign(str, 1, ret_val, &need_add);
}
