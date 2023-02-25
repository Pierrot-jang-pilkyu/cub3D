/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:47:47 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 18:50:46 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
		game->ray.width, game->ray.height, game->title);
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->img.width, game->img.height);
	game->img.addr = (unsigned int *)mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->pixel = init_pixel(&game->img);
	put_xpm_to_img(game, &game->map);
	get_addr(&game->map);
}
