/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:04:00 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 17:04:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	file_check(const char *filename)
{
	int		len;
	char	*temp;

	len = ft_strlen(filename);
	temp = ft_substr(filename, len - 4, 4);
	if (ft_strncmp((const char *)temp, ".cub", 4) != 0)
		put_error("The file extension is incorrect.");
	free(temp);
}

void	set_base_color(t_game *game)
{
	t_color	*color;
	t_map	*map;

	color = &game->color;
	map = &game->map;
	color->ceil = (map->ceil[0] << 16) + (map->ceil[1] << 8) + map->ceil[2];
	color->floor = (map->floor[0] << 16) + (map->floor[1] << 8) + map->floor[2];
}

int	parsing(t_game *game)
{
	int	fd;

	file_check(game->fpath);
	fd = open(game->fpath, O_RDONLY);
	if (fd == -1)
		return (1);
	if (get_cub(fd, &game->map))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (!valid_maze(&game->map))
		return (1);
	set_base_color(game);
	return (0);
}
