/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:39:07 by odessein          #+#    #+#             */
/*   Updated: 2022/11/24 12:57:12 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>

typedef struct	s_data{
	int		floor_color;
	int		ceilling_color;
	char	*east_texture;
	char	*north_texture;
	char	*west_texture;
	char	*south_texture;
}			t_data;

typedef struct	s_player{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		x;
	int		y;
}			t_player;

typedef struct	s_vision{
	int		fov;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		horizontal_angle;
}			t_vision;

typedef struct	s_game_info{
	t_player	player;
	t_vision	camera;
	t_data		data;
}				t_game_info;

#endif
