/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:14:58 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 09:38:57 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_map *map, int steps)
{
	char	str[5];

	if (steps == 0)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			5, (map->col_len * SIZE) + 15, 0xFFFFFF, "Moves");
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			5, (map->col_len * SIZE) + 30, 0xFFFFFF, "0000");
		return ;
	}
	str[0] = (steps / 1000) % 10 + '0';
	str[1] = (steps / 100) % 10 + '0';
	str[2] = (steps / 10) % 10 + '0';
	str[3] = steps % 10 + '0';
	str[4] = '\0';
	draw_tile(map, map->img->cvr, (map->col_len) * SIZE + 15, 0);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		5, (map->col_len * SIZE) + 30, 0xFFFFFF, str);
}

void	draw_animation(t_map *map, int frame)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->col_len)
	{
		x = 0;
		while (x < map->row_len)
		{
			if (map->arr[y][x] == 'C')
				draw_tile(map, map->img->c[frame], y * SIZE, x * SIZE);
			x++;
		}
		y++;
	}
	if (map->m[0] > 0)
		draw_tile(map, map->img->m[frame], map->m[1] * SIZE, map->m[2] * SIZE);
}

int	loop_sprite(t_map *map)
{
	static int	frame = 0;
	static int	dir = 1;
	static int	timer = 0;

	if (timer >= 10000)
	{
		timer = 0;
		draw_animation(map, frame);
		if (frame >= 3)
			dir = -1;
		else if (frame <= 0)
			dir = 1;
		frame += dir;
	}
	timer++;
	return (0);
}

int	ft_loop(t_map *map)
{
	loop_sprite(map);
	if (map->m[0] > 0)
	{
		enemy_logic(map);
	}
	return (0);
}
