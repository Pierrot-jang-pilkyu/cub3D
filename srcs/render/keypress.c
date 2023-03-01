/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:57:59 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 19:20:41 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	t_key	*key;

	key = &game->key;
	if (keycode == KEY_W)
		key->key_w = 1;
	else if (keycode == KEY_S)
		key->key_s = 1;
	else if (keycode == KEY_A)
		key->key_a = 1;
	else if (keycode == KEY_D)
		key->key_d = 1;
	else if (keycode == KEY_ARR_L)
		key->key_arr_l = 1;
	else if (keycode == KEY_ARR_R)
		key->key_arr_r = 1;
	else if (keycode == KEY_ESC)
		key->key_esc = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	t_key	*key;

	key = &game->key;
	if (keycode == KEY_W)
		key->key_w = 0;
	else if (keycode == KEY_S)
		key->key_s = 0;
	else if (keycode == KEY_A)
		key->key_a = 0;
	else if (keycode == KEY_D)
		key->key_d = 0;
	else if (keycode == KEY_ARR_L)
		key->key_arr_l = 0;
	else if (keycode == KEY_ARR_R)
		key->key_arr_r = 0;
	else if (keycode == KEY_ESC)
		key->key_esc = 0;
	return (0);
}

void	player_move(t_game *game)
{
	double	dir[2];
	double	perp[2];
	t_ray	*ray;
	t_key	*key;

	ray = &game->ray;
	key = &game->key;
	dir[X] = ray->dir[X] * 0.5;
	dir[Y] = ray->dir[Y] * 0.5;
	perp[X] = -dir[Y];
	perp[Y] = dir[X];
	if (key->key_w)
		move_add(game, dir);
	if (key->key_s)
		move_sub(game, dir);
	if (key->key_a)
		move_add(game, perp);
	if (key->key_d)
		move_sub(game, perp);
	if (key->key_arr_l)
		move_ccw(game);
	if (key->key_arr_r)
		move_cw(game);
	if (key->key_esc)
		game_close(game);
}
