/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:58:47 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 09:47:42 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (map->arr[i][j] == '0')
				draw_tile(map, map->img->f, i * SIZE, j * SIZE);
			else if (map->arr[i][j] == 'P')
				draw_tile(map, map->img->p[3], i * SIZE, j * SIZE);
			else if (map->arr[i][j] == 'E')
				draw_tile(map, map->img->e, i * SIZE, j * SIZE);
			else if (map->arr[i][j] == 'C')
				draw_tile(map, map->img->c[0], i * SIZE, j * SIZE);
			else if (map->arr[i][j] == 'M')
				draw_tile(map, map->img->m[0], i * SIZE, j * SIZE);
			else
				draw_tile(map, map->img->w[wall_bitmask(map, i, j)],
					i * SIZE, j * SIZE);
		}
	}
	print_moves(map, 0);
}

void	draw_player(t_map *map, int dir_x, int dir_y)
{
	static int	mouth = 0;
	int			mask;

	mask = 0;
	mouth = -mouth + 1;
	if (mouth)
		mask = 4;
	else if (dir_y)
		mask = dir_y + 1;
	else if (dir_x)
		mask = dir_x + 2;
	draw_tile(map, map->img->p[mask], map->p[1] * SIZE, map->p[2] * SIZE);
}

void	update_player(t_map *map, int dir_x, int dir_y)
{
	draw_tile(map, map->img->f, map->p[1] * SIZE, map->p[2] * SIZE);
	map->p[2] += dir_x;
	map->p[1] += dir_y;
	if (map->arr[map->p[1]][map->p[2]] == 'C')
	{
		map->arr[map->p[1]][map->p[2]] = '0';
		map->c_count -= 1;
		if (map->c_count == 0)
			draw_tile(map, map->img->e_o, map->e[1] * SIZE, map->e[2] * SIZE);
	}
	if (map->p[2] == map->m[2] && map->p[1] == map->m[1])
		ft_close(-3, map);
	if (map->c_count == 0 && map->p[2] == map->e[2] && map->p[1] == map->e[1])
		ft_close(-2, map);
	if (map->arr[map->p[1] - dir_y][map->p[2] - dir_x] == 'E')
	{
		draw_tile(map, map->img->e,
			(map->p[1] - dir_y) * SIZE, (map->p[2] - dir_x) * SIZE);
		if (map->c_count == 0)
			draw_tile(map, map->img->e_o,
				(map->p[1] - dir_y) * SIZE, (map->p[2] - dir_x) * SIZE);
	}
	draw_player(map, dir_x, dir_y);
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
		print_moves(map, steps);
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
			map->row_len * SIZE, (map->col_len + 1) * SIZE, "so_long");
	err = load_img(map);
	if (err != 0)
		ft_close(err, map);
	draw_map(map);
	mlx_key_hook(map->win_ptr, ft_key_hook, map);
	mlx_hook(map->win_ptr, 17, 0, ft_close_x, map);
	mlx_loop_hook(map->mlx_ptr, ft_loop, map);
	mlx_loop(map->mlx_ptr);
	return ;
}
