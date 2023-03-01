/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:18:59 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 19:01:30 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_vertical(t_game *game, int x, unsigned int color)
{
	int		y;
	t_ray	*ray;

	ray = &game->ray;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
}

void	draw_base(t_game *game)
{
	t_pixel	**pixel;
	int		x;
	int		y;

	pixel = game->pixel;
	y = -1;
	while (++y < game->img.height / 2)
	{
		x = -1;
		while (++x < game->img.width)
			*(pixel[x][y].color) = game->color.ceil;
	}
	y--;
	while (++y < game->img.height)
	{
		x = -1;
		while (++x < game->img.width)
			*(pixel[x][y].color) = game->color.floor;
	}
}
