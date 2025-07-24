/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:39:26 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/24 10:19:35 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(int code, t_map *map)
{
	if (code == -2)
		write(1, "YOU WIN!\n", 9);
	else if (code == -3)
		write(1, "YOU LOSE!\n", 10);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	destroy_images(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	ft_err_handler(code, map);
	exit(0);
	return (0);
}

int	ft_close_x(t_map *map)
{
	return (ft_close(-1, map));
}

void	ft_err_handler(int code, t_map *map)
{
	if (map && code != 0)
	{
		if (map->arr_copy)
			free(map->arr_copy);
		if (map->arr)
			ft_free_split(map->arr);
		free(map);
	}
	if (code <= 0)
		return ;
	if (code == 42)
		write(2, "Malloc Error\n", 13);
	if (code == 1)
		write(2, "Map File Invalid\n", 17);
	if (code == 2)
		write(2, "Invalid Map\n", 12);
	if (code == 3)
		write(2, "Incorrect amount of Players, \
Exits, Collectibles or Monsters\n", 61);
	if (code == 4)
		write(2, "Map is impossible to complete\n", 30);
	if (code == 5)
		write(2, "Image did not load correctly\n", 29);
	write(2, "Error\n", 6);
	exit(1);
}
