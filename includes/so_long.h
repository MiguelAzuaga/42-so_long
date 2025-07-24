/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:23:32 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 07:49:44 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SIZE 32
# define PLAYER "sprites/player/3.xpm"
# define FLOOR "sprites/floor.xpm"
# define WALL "sprites/wall/0.xpm"
# define EXIT "sprites/exit.xpm"
# define EXIT_O "sprites/exit_o.xpm"
# define COIN "sprites/coin/3.xpm"

typedef struct s_img
{
	void	*p;
	void	*e;
	void	*e_o;
	void	*c;
	void	*f;
	void	*w;
}	t_img;

typedef struct s_map
{
	char	*arr_copy;
	char	**arr;
	int		row_len;
	int		col_len;
	int		p[3];
	int		e[3];
	int		c[3];
	int		c_count;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}	t_map;

int		parser(t_map *map);
int		call_flood_fill(t_map *map, int y, int x);
void	ft_err_handler(int code, t_map *map);
int		ft_close(int code, t_map *map);
void	ft_render(t_map *map);
void	destroy_images(t_map *map);
int		load_img(t_map *map);
void	draw_tile(t_map *map, void *tile, int y, int x);
void	update_player(t_map *map, int dir_x, int dir_y);

#endif
