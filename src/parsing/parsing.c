/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:44:55 by odessein          #+#    #+#             */
/*   Updated: 2022/11/24 11:19:15 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static bool	check_extension(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (i >= 5 && name[i - 1] == 'b' && name[i - 2] == 'u' && name[i - 3] == 'c' && name[i - 4] == '.')
		return (true);
	else
		return (false);
}

bool	parsing(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (false);
	if (!check_extension(av[1]))
		return (false);
	return (true);
}
