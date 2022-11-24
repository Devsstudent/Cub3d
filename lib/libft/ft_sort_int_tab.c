/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:29:45 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:42:53 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_swap(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
	return ;
}

static int	ft_check_sorting(int *tab, int size)
{
	int	n;

	n = 0;
	while (n < size - 1)
	{
		if (*tab > *(tab + 1))
			return (1);
		tab += 1;
		n += 1;
	}
	return (0);
}

void	ft_sort_int_tab(int	*tab, int size)
{
	int	browser_tab;

	while (ft_check_sorting(tab, size) != 0)
	{
		browser_tab = 0;
		while (browser_tab < (size - 1))
		{
			if (*(tab + browser_tab) > *(tab + browser_tab + 1))
			{
				ft_swap((tab + browser_tab), (tab + 1 + browser_tab));
			}
			browser_tab += 1;
		}
	}
}
