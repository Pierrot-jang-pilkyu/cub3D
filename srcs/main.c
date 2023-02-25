/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:02:59 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 21:16:13 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init(&game);
		game.fpath = ft_strdup(av[1]);
		if (parsing(&game))
			put_error("The .cub file error.");
		render(&game);
		window_init(&game);
		img_init(&game);
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
		mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &game_close, &game);
		mlx_loop_hook(game.mlx, &ft_mlx_img, &game);
		mlx_loop(game.mlx);
	}
	else
		put_error("Arguments error.");
	return (0);
}
