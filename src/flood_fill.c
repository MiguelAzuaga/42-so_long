/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:02:39 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/21 07:31:04 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map *map, int y, int x, int *end)
{
	if (y < 0 || y >= map->col_len || x < 0 || x >= map->row_len)
		return (4);
	if (map->arr[y][x] == '-' || map->arr[y][x] == '1')
		return (4);
	if (map->arr[y][x] == 'E')
		(*end)++;
	if (map->arr[y][x] == 'C')
		map->c_count--;
	map->arr[y][x] = '-';
	flood_fill(map, y + 1, x, end);
	flood_fill(map, y - 1, x, end);
	flood_fill(map, y, x + 1, end);
	flood_fill(map, y, x - 1, end);
	if (*end == 1 && map->c_count == 0)
		return (0);
	return (4);
}

int	call_flood_fill(t_map *map, int y, int x)
{
	char	**tmp;
	int		err_code;
	int		validate;
	int		c_total;

	validate = 0;
	c_total = map->c_count;
	tmp = ft_split(map->arr_copy, '\n');
	err_code = flood_fill(map, y, x, &validate);
	ft_free_split(map->arr);
	map->arr = tmp;
	map->c_count = c_total;
	ft_err_handler(err_code, map);
	return (0);
}
