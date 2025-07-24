/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:02:36 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/19 20:05:18 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int code, t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	destroy_images(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	ft_err_handler(code, map);
	exit(0);
	return (0);
}

void	destroy_images(t_map *map)
{
	if (map->img)
	{
		if (map->img->p)
			mlx_destroy_image(map->mlx_ptr, map->img->p);
		if (map->img->e)
			mlx_destroy_image(map->mlx_ptr, map->img->e);
		if (map->img->e_o)
			mlx_destroy_image(map->mlx_ptr, map->img->e_o);
		if (map->img->c)
			mlx_destroy_image(map->mlx_ptr, map->img->c);
		if (map->img->f)
			mlx_destroy_image(map->mlx_ptr, map->img->f);
		if (map->img->w)
			mlx_destroy_image(map->mlx_ptr, map->img->w);
		free(map->img);
	}
	return ;
}

int	load_img(t_map *map)
{
	int	w;
	int	h;

	map->img->p = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER, &w, &h);
	if (!map->img->p)
		return (5);
	map->img->e = mlx_xpm_file_to_image(map->mlx_ptr, EXIT, &w, &h);
	if (!map->img->e)
		return (5);
	map->img->e_o = mlx_xpm_file_to_image(map->mlx_ptr, EXIT_O, &w, &h);
	if (!map->img->e_o)
		return (5);
	map->img->c = mlx_xpm_file_to_image(map->mlx_ptr, COIN, &w, &h);
	if (!map->img->c)
		return (5);
	map->img->f = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR, &w, &h);
	if (!map->img->f)
		return (5);
	map->img->w = mlx_xpm_file_to_image(map->mlx_ptr, WALL, &w, &h);
	if (!map->img->w)
		return (5);
	return (0);
}

void	draw_tile(t_map *map, void *tile, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, tile, x * 32, y * 32);
}
