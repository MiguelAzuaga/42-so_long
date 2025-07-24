/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:13:41 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/21 12:12:54 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	wall_bitmask(t_map *map, int y, int x)
{
	int	mask;

	mask = 0;
	if (y > 0 && map->arr[y - 1][x] == '1')
		mask |= 1;
	if (x > 0 && map->arr[y][x - 1] == '1')
		mask |= 2;
	if (y < map->col_len - 1 && map->arr[y + 1][x] == '1')
		mask |= 4;
	if (x < map->row_len - 1 && map->arr[y][x + 1] == '1')
		mask |= 8;
	return (mask);
}

int	load_player(t_map *map, int w, int h)
{
	map->img->p[0] = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER0, &w, &h);
	map->img->p[1] = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER1, &w, &h);
	map->img->p[2] = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER2, &w, &h);
	map->img->p[3] = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER3, &w, &h);
	map->img->p[4] = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER4, &w, &h);
	if (!map->img->p[0] || !map->img->p[1]
		|| !map->img->p[2] || !map->img->p[3] || !map->img->p[4])
		return (5);
	return (0);
}

int	load_enemy(t_map *map, int w, int h)
{
	map->img->m[0] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY0, &w, &h);
	map->img->m[1] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY1, &w, &h);
	map->img->m[2] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY2, &w, &h);
	map->img->m[3] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY3, &w, &h);
	if (!map->img->m[0] || !map->img->m[1]
		|| !map->img->m[2] || !map->img->m[3])
		return (5);
	return (0);
}

int	load_coin(t_map *map, int w, int h)
{
	map->img->c[0] = mlx_xpm_file_to_image(map->mlx_ptr, COIN0, &w, &h);
	map->img->c[1] = mlx_xpm_file_to_image(map->mlx_ptr, COIN1, &w, &h);
	map->img->c[2] = mlx_xpm_file_to_image(map->mlx_ptr, COIN2, &w, &h);
	map->img->c[3] = mlx_xpm_file_to_image(map->mlx_ptr, COIN3, &w, &h);
	if (!map->img->c[0] || !map->img->c[1]
		|| !map->img->c[2] || !map->img->c[3])
		return (5);
	return (0);
}

int	load_walls(t_map *map, int w, int h)
{
	map->img->w[0] = mlx_xpm_file_to_image(map->mlx_ptr, WALL0, &w, &h);
	map->img->w[1] = mlx_xpm_file_to_image(map->mlx_ptr, WALL1, &w, &h);
	map->img->w[2] = mlx_xpm_file_to_image(map->mlx_ptr, WALL2, &w, &h);
	map->img->w[3] = mlx_xpm_file_to_image(map->mlx_ptr, WALL3, &w, &h);
	map->img->w[4] = mlx_xpm_file_to_image(map->mlx_ptr, WALL4, &w, &h);
	map->img->w[5] = mlx_xpm_file_to_image(map->mlx_ptr, WALL5, &w, &h);
	map->img->w[6] = mlx_xpm_file_to_image(map->mlx_ptr, WALL6, &w, &h);
	map->img->w[7] = mlx_xpm_file_to_image(map->mlx_ptr, WALL7, &w, &h);
	map->img->w[8] = mlx_xpm_file_to_image(map->mlx_ptr, WALL8, &w, &h);
	map->img->w[9] = mlx_xpm_file_to_image(map->mlx_ptr, WALL9, &w, &h);
	map->img->w[10] = mlx_xpm_file_to_image(map->mlx_ptr, WALL10, &w, &h);
	map->img->w[11] = mlx_xpm_file_to_image(map->mlx_ptr, WALL11, &w, &h);
	map->img->w[12] = mlx_xpm_file_to_image(map->mlx_ptr, WALL12, &w, &h);
	map->img->w[13] = mlx_xpm_file_to_image(map->mlx_ptr, WALL13, &w, &h);
	map->img->w[14] = mlx_xpm_file_to_image(map->mlx_ptr, WALL14, &w, &h);
	map->img->w[15] = mlx_xpm_file_to_image(map->mlx_ptr, WALL15, &w, &h);
	if (!map->img->w[0] || !map->img->w[1] || !map->img->w[2]
		|| !map->img->w[3] || !map->img->w[4] || !map->img->w[5]
		|| !map->img->w[6] || !map->img->w[7] || !map->img->w[8]
		|| !map->img->w[9] || !map->img->w[10] || !map->img->w[11]
		|| !map->img->w[12] || !map->img->w[13] || !map->img->w[14]
		|| !map->img->w[15])
		return (5);
	return (0);
}
