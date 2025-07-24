/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:40:38 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/24 09:12:40 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <limits.h>
#include <stdint.h>

void	update_enemy(t_map *map, int dir_x, int dir_y)
{
	draw_tile(map, map->img->f, map->m[1] * SIZE, map->m[2] * SIZE);
	map->m[2] += dir_x;
	map->m[1] += dir_y;
	draw_tile(map, map->img->m[0], map->m[1] * SIZE, map->m[2] * SIZE);
	if (map->p[2] == map->m[2] && map->p[1] == map->m[1])
		ft_close(-3, map);
}

void	enemy_logic(t_map *map)
{
	static int	timer = 0;
	static int	r;
	static int	dir_x = 0;
	static int	dir_y = 0;

	if (timer >= 100000)
	{
		timer = 0;
		while ((dir_x == 0 && dir_y == 0)
			|| map->arr[map->m[1] + dir_y][map->m[2] + dir_x] == '1'
			|| map->arr[map->m[1] + dir_y][map->m[2] + dir_x] == 'C'
			|| map->arr[map->m[1] + dir_y][map->m[2] + dir_x] == 'E')
		{
			r = rand() % 4;
			dir_x = 0;
			dir_y = 0;
			if (r % 2 == 0)
				dir_y = r - 1;
			else
				dir_x = r - 2;
		}
		update_enemy(map, dir_x, dir_y);
	}
	timer++;
}
