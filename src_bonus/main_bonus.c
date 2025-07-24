/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:02:29 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/24 06:33:49 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <fcntl.h>
#include <time.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc(s1_len + s2_len + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	while (i < s1_len)
		new[i++] = s1[j++];
	j = 0;
	while (j < s2_len && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

int	get_map(char *map_file, t_map *map)
{
	int		fd;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	tmp = get_next_line(fd);
	map->arr_copy = tmp;
	map->row_len = ft_strlen(tmp) - 1;
	while (tmp)
	{
		tmp = get_next_line(fd);
		map->arr_copy = ft_strjoin_free(map->arr_copy, tmp);
		free(tmp);
	}
	close(fd);
	if (!map->arr_copy || !map->arr_copy[0])
		return (1);
	map->arr = ft_split(map->arr_copy, '\n');
	if (!map->arr)
		return (1);
	fd = 0;
	while (map->arr[fd++])
		map->col_len++;
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	if (argc != 2)
		return (write(2, "Usage: ./so_long <map_name.ber>\n", 32));
	i = 0;
	while (argv[1][i])
		i++;
	if (i < 5 || argv[1][i - 5] == '/'
		|| argv[1][i - 4] != '.' || argv[1][i - 3] != 'b'
		|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r' )
		return (write(2, "Usage: ./so_long <map_name.ber>\n", 32));
	map = malloc(sizeof(t_map));
	if (!map)
		ft_err_handler(42, NULL);
	*map = (t_map){0};
	ft_err_handler(get_map(argv[1], map), map);
	ft_err_handler(parser(map), map);
	srand(time(NULL));
	ft_render(map);
	ft_err_handler(-1, map);
	return (0);
}
