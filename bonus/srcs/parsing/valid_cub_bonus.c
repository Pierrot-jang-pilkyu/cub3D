/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cub_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:03 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 21:41:31 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	valid_path(char *str)
{
	int		ret;
	int		fd;
	int		flag;
	int		len;
	char	**temp;

	fd = -2;
	ret = 1;
	temp = ft_split(str, ' ');
	len = ft_strlen(temp[0]);
	flag = (!ft_strncmp("NO", temp[0], len) | !ft_strncmp("SO", temp[0], len) \
		| !ft_strncmp("WE", temp[0], len) | !ft_strncmp("EA", temp[0], len));
	if (flag && temp[1])
	{
		fd = open(temp[1], O_RDONLY);
		if (fd == -1)
			ret = 0;
		else
			close(fd);
	}
	else
		ret = 0;
	safety_dimention_free(&temp);
	return (ret);
}

int	valid_c(char *str, t_map *map)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == ' ' \
			|| *str == 'N' || *str == 'S' || *str == 'W' || *str == 'E'))
			return (0);
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
			map->player++;
		if (map->player > 1)
			return (0);
		str++;
	}
	return (1);
}

int	valid_cub(char *str, t_map *map)
{
	if (valid_color(str))
		return (1);
	if (valid_path(str))
		return (2);
	if (valid_c(str, map))
		return (3);
	return (0);
}
