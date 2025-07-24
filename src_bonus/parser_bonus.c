/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:02:43 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/24 10:01:54 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_component(int component[3], int *count, int y, int x)
{
	component[0]++;
	component[1] = y;
	component[2] = x;
	if (count != NULL)
		(*count)++;
}

static int	find_components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (map->arr[i][j] == 'P')
				set_component(map->p, NULL, i, j);
			else if (map->arr[i][j] == 'E')
				set_component(map->e, NULL, i, j);
			else if (map->arr[i][j] == 'C')
				set_component(map->c, &map->c_count, i, j);
			else if (map->arr[i][j] == 'M')
				set_component(map->m, NULL, i, j);
		}
		i++;
	}
	if (map->p[0] != 1 || map->e[0] != 1 || map->c[0] == 0 || map->m[0] > 1)
		return (3);
	return (0);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if ((j == 0 || j + 1 == map->row_len) && map->arr[i][j] != '1')
				return (2);
			if ((i == 0 || i + 1 == map->col_len) && map->arr[i][j] != '1')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr_copy[i + 1])
	{
		if (map->arr_copy[i] == '\n' && map->arr_copy[i + 1] == '\n')
			return (2);
		i++;
	}
	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j]
			&& (map->arr[i][j] == '1' || map->arr[i][j] == '0'
			|| map->arr[i][j] == 'P' || map->arr[i][j] == 'E'
			|| map->arr[i][j] == 'C' || map->arr[i][j] == 'M'))
			j++;
		if (j != map->row_len)
			return (2);
		i++;
	}
	return (0);
}

int	parser(t_map *map)
{
	ft_err_handler(valid_chars(map), map);
	ft_err_handler(check_walls(map), map);
	ft_err_handler(find_components(map), map);
	ft_err_handler(call_flood_fill(map, map->p[1], map->p[2]), map);
	return (0);
}
