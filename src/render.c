/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:02:47 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 07:39:12 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close_x(t_map *map)
{
	return (ft_close(-1, map));
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (map->arr[i][j] == '0')
				draw_tile(map, map->img->f, i, j);
			else if (map->arr[i][j] == 'P')
				draw_tile(map, map->img->p, i, j);
			else if (map->arr[i][j] == 'E')
				draw_tile(map, map->img->e, i, j);
			else if (map->arr[i][j] == 'C')
				draw_tile(map, map->img->c, i, j);
			else
				draw_tile(map, map->img->w, i, j);
			j++;
		}
		i++;
	}
}

void	update_player(t_map *map, int dir_x, int dir_y)
{
	draw_tile(map, map->img->f, map->p[1], map->p[2]);
	map->p[2] += dir_x;
	map->p[1] += dir_y;
	if (map->arr[map->p[1]][map->p[2]] == 'C')
	{
		map->arr[map->p[1]][map->p[2]] = '0';
		map->c_count -= 1;
		if (map->c_count == 0)
			draw_tile(map, map->img->e_o, map->e[1], map->e[2]);
	}
	if (map->c_count == 0 && map->p[2] == map->e[2] && map->p[1] == map->e[1])
	{
		write(1, "YOU WIN!\n", 9);
		ft_close(-1, map);
	}
	if (map->arr[map->p[1] - dir_y][map->p[2] - dir_x] == 'E')
	{
		draw_tile(map, map->img->e, map->p[1] - dir_y, map->p[2] - dir_x);
		if (map->c_count == 0)
			draw_tile(map, map->img->e_o, map->p[1] - dir_y, map->p[2] - dir_x);
	}
	draw_tile(map, map->img->p, map->p[1], map->p[2]);
}

int	ft_key_hook(int keycode, t_map *map)
{
	int			dir_x;
	int			dir_y;
	static int	steps = 0;

	dir_x = 0;
	dir_y = 0;
	if (keycode == ESC)
		ft_close(-1, map);
	if (keycode == W || keycode == UP)
		dir_y = -1;
	if (keycode == A || keycode == LEFT)
		dir_x = -1;
	if (keycode == S || keycode == DOWN)
		dir_y = 1;
	if (keycode == D || keycode == RIGHT)
		dir_x = 1;
	if ((dir_x != 0 || dir_y != 0)
		&& map->arr[map->p[1] + dir_y][map->p[2] + dir_x] != '1')
	{
		steps++;
		ft_printf("Moves:%d\n", steps);
		update_player(map, dir_x, dir_y);
	}
	return (0);
}

void	ft_render(t_map *map)
{
	int	err;

	map->img = malloc(sizeof(t_img));
	if (!map->img)
		ft_err_handler(42, map);
	*map->img = (t_img){0};
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			map->row_len * SIZE, (map->col_len) * SIZE, "so_long");
	err = load_img(map);
	if (err != 0)
		ft_close(err, map);
	draw_map(map);
	mlx_key_hook(map->win_ptr, ft_key_hook, map);
	mlx_hook(map->win_ptr, 17, 0, ft_close_x, map);
	mlx_loop(map->mlx_ptr);
	return ;
}
