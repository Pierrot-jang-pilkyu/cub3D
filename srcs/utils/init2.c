/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:25:21 by pjang             #+#    #+#             */
/*   Updated: 2023/02/28 17:24:36 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_key(t_key *key)
{
	key->key_w = 0;
	key->key_s = 0;
	key->key_a = 0;
	key->key_d = 0;
	key->key_arr_l = 0;
	key->key_arr_r = 0;
	key->key_esc = 0;
}

t_pixel	**init_pixel(t_img *img)
{
	t_pixel	**pixel;
	int		x;
	int		y;

	pixel = (t_pixel **)malloc(sizeof(t_pixel *) * (img->width));
	if (!pixel)
		return (NULL);
	x = -1;
	while (++x < img->width)
	{
		pixel[x] = (t_pixel *)malloc(sizeof(t_pixel) * (img->height));
		if (!pixel[x])
			return (NULL);
		y = -1;
		while (++y < img->height)
		{
			pixel[x][y].dist = INFINITY;
			pixel[x][y].color = (unsigned int *)((char *)img->addr + \
				(img->line_length * y + img->bits_per_pixel / 8 * x));
		}
	}
	return (pixel);
}
