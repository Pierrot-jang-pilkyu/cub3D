/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:41:53 by pjang             #+#    #+#             */
/*   Updated: 2023/02/28 20:07:23 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

# define X 0
# define Y 1

# define N 0
# define S 1
# define W 2
# define E 3

# define WIDTH 640
# define HEIGHT 480

# define PI 3.141592653
# define D1 0.01745329251

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY_NOTIFY 17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ARR_L	123
# define KEY_ARR_R	124

typedef struct s_pixel
{
	double			dist;
	unsigned int	*color;
}				t_pixel;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	char			*path;
	unsigned int	*color;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct s_color
{
	unsigned int	ceil;
	unsigned int	floor;
}				t_color;

typedef struct s_ray
{
	int		width;
	int		height;
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	camera_x;
	double	ray_dir[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	wall_dist;
	int		step[2];
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}				t_ray;

typedef struct s_map
{
	t_list	*lst_map;
	char	**maze;
	int		width;
	int		height;
	int		floor[3];
	int		ceil[3];
	int		in_err;
	int		tex_num;
	int		tex[2];
	double	tex_pos;
	double	step;
	t_img	texture[4];
}				t_map;

typedef struct s_key
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_arr_l;
	int	key_arr_r;
	int	key_esc;
}				t_key;

typedef struct s_game
{
	char	*fpath;
	t_pixel	**pixel;
	t_map	map;
	t_color	color;
	t_ray	ray;
	t_img	img;
	t_key	key;
	void	*mlx;
	void	*win;
	char	*title;
}				t_game;

// utils

void	print_maze(t_map *map);
void	print_maze2(t_map *map, char **temp);

int		ft_max(int a, int b);

int		init(t_game *game);
void	init_key(t_key *key);
t_pixel	**init_pixel(t_img *img);

void	put_error(char *message);
void	safety_free(void **str);
void	safety_dimention_free(char ***strs);

// parsing

int		valid_cub(char *str);
int		valid_color(char *str);
int		valid_in(t_map *map);
int		valid_maze(t_map *map);

int		get_color(char *str, t_map *map);
int		get_path(char *str, t_map *map);
int		get_map(char *str, t_map *map);
int		get_maze(t_map *map);
int		get_cub(int fd, t_map *map);
int		get_cub2(int flag, t_map *map, char *temp);
int		parsing(t_game *game);

// render

void	window_init(t_game *game);
void	img_init(t_game *game);
void	get_color_in_texture(t_game *game, t_map *map);

int		render(t_game *game);

void	raycasting(t_game *game);
void	dda(t_map *map, t_ray *ray);
void	calculate_dist(t_ray *ray);
void	calculate_hline(t_ray *ray);
int		ft_mlx_img(t_game *game);
void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);

void	draw_vertical(t_game *game, int x, unsigned int color);
void	draw_base(t_game *game);

void	move_add(t_game *game, double vec[2]);
void	move_sub(t_game *game, double vec[2]);
void	move_ccw(t_game *game);
void	move_cw(t_game *game);

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

void	player_move(t_game *game);

int		game_close(t_game *game);

#endif
