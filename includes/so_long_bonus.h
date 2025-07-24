/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:39:12 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/22 07:45:10 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define PLAYER0 "sprites/player/0.xpm"
# define PLAYER1 "sprites/player/1.xpm"
# define PLAYER2 "sprites/player/2.xpm"
# define PLAYER3 "sprites/player/3.xpm"
# define PLAYER4 "sprites/player/4.xpm"
# define FLOOR "sprites/floor.xpm"
# define WALL0 "sprites/wall/0.xpm"
# define WALL1 "sprites/wall/1.xpm"
# define WALL2 "sprites/wall/2.xpm"
# define WALL3 "sprites/wall/3.xpm"
# define WALL4 "sprites/wall/4.xpm"
# define WALL5 "sprites/wall/5.xpm"
# define WALL6 "sprites/wall/6.xpm"
# define WALL7 "sprites/wall/7.xpm"
# define WALL8 "sprites/wall/8.xpm"
# define WALL9 "sprites/wall/9.xpm"
# define WALL10 "sprites/wall/10.xpm"
# define WALL11 "sprites/wall/11.xpm"
# define WALL12 "sprites/wall/12.xpm"
# define WALL13 "sprites/wall/13.xpm"
# define WALL14 "sprites/wall/14.xpm"
# define WALL15 "sprites/wall/15.xpm"
# define EXIT "sprites/exit.xpm"
# define EXIT_O "sprites/exit_o.xpm"
# define COIN0 "sprites/coin/0.xpm"
# define COIN1 "sprites/coin/1.xpm"
# define COIN2 "sprites/coin/2.xpm"
# define COIN3 "sprites/coin/3.xpm"
# define COVER "sprites/cover.xpm"
# define ENEMY0 "sprites/enemy/0.xpm"
# define ENEMY1 "sprites/enemy/1.xpm"
# define ENEMY2 "sprites/enemy/2.xpm"
# define ENEMY3 "sprites/enemy/3.xpm"

typedef struct s_img
{
	void	*p[5];
	void	*e;
	void	*e_o;
	void	*c[4];
	void	*f;
	void	*w[16];
	void	*cvr;
	void	*m[4];
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
	int		m[3];
	int		c_count;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}	t_map;

int		ft_close(int code, t_map *map);
void	ft_err_handler(int code, t_map *map);
int		ft_close_x(t_map *map);

int		parser(t_map *map);
int		call_flood_fill(t_map *map, int y, int x);
void	ft_render(t_map *map);
void	destroy_images(t_map *map);
int		load_img(t_map *map);
void	draw_tile(t_map *map, void *tile, int y, int x);
int		wall_bitmask(t_map *map, int y, int x);
void	print_moves(t_map *map, int steps);

int		ft_loop(t_map *map);

int		load_walls(t_map *map, int w, int h);
int		load_player(t_map *map, int w, int h);
int		load_enemy(t_map *map, int w, int h);
int		load_coin(t_map *map, int w, int h);
int		loop_sprite(t_map *map);

void	enemy_logic(t_map *map);

#endif
