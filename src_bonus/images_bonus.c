/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:14:09 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 07:38:03 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_image_array(void *mlx_ptr, void **sprites, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (sprites[i])
			mlx_destroy_image(mlx_ptr, sprites[i]);
		i++;
	}
}

void	destroy_images(t_map *map)
{
	if (map->img)
	{
		if (map->img->e)
			mlx_destroy_image(map->mlx_ptr, map->img->e);
		if (map->img->e_o)
			mlx_destroy_image(map->mlx_ptr, map->img->e_o);
		if (map->img->f)
			mlx_destroy_image(map->mlx_ptr, map->img->f);
		destroy_image_array(map->mlx_ptr, map->img->m, 4);
		destroy_image_array(map->mlx_ptr, map->img->c, 4);
		destroy_image_array(map->mlx_ptr, map->img->p, 5);
		destroy_image_array(map->mlx_ptr, map->img->w, 16);
		if (map->img->cvr)
			mlx_destroy_image(map->mlx_ptr, map->img->cvr);
		free(map->img);
	}
	return ;
}

int	load_img(t_map *map)
{
	int	w;
	int	h;

	map->img->e = mlx_xpm_file_to_image(map->mlx_ptr, EXIT, &w, &h);
	if (!map->img->e)
		return (5);
	map->img->e_o = mlx_xpm_file_to_image(map->mlx_ptr, EXIT_O, &w, &h);
	if (!map->img->e_o)
		return (5);
	map->img->f = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR, &w, &h);
	if (!map->img->f)
		return (5);
	if (load_coin(map, w, h) != 0 || load_player(map, w, h) != 0
		|| load_walls(map, w, h) != 0 || load_enemy(map, w, h) != 0)
		return (5);
	map->img->cvr = mlx_xpm_file_to_image(map->mlx_ptr, COVER, &w, &h);
	return (0);
}

void	draw_tile(t_map *map, void *tile, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, tile, x, y);
}
