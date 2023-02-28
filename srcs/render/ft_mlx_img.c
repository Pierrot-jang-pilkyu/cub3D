/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:58:18 by pjang             #+#    #+#             */
/*   Updated: 2023/02/28 18:02:13 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_colors(t_img *texture)
{
	int x;
	int y;

	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width)
		{
			texture->color[y * texture->height + x] = texture->addr[y * texture->height + x];
			x++;
		}
		y++;
	}
}

void	get_color_in_texture(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->texture[i].img = mlx_xpm_file_to_image(game->mlx, \
			map->texture[i].path, &map->texture[i].width, &map->texture[i].height);
		map->texture[i].addr = (unsigned int *)mlx_get_data_addr(\
			map->texture[i].img, &map->texture[i].bits_per_pixel, \
			&map->texture[i].line_length, &map->texture[i].endian);
		get_colors(&map->texture[i]);
		mlx_destroy_image(game->mlx, map->texture[i].img);
		i++;
	}
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)((char *)img->addr + \
		(img->line_length * y + img->bits_per_pixel / 8 * x));
	*dst = color;
}

void	scene_refresh(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}

int	ft_mlx_img(t_game *game)
{
	scene_refresh(game);
	player_move(game);
	draw_base(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
