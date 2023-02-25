/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:03 by pjang             #+#    #+#             */
/*   Updated: 2023/02/24 20:57:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_color2(char *str)
{
	int		i;
	char	**temp;

	if (str == NULL)
		return (0);
	temp = ft_split(str, ',');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (i == 3)
	{
		i = 0;
		while (i < 3)
		{
			if (!(0 <= ft_atoi(temp[i]) && ft_atoi(temp[i]) < 256))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	valid_color(char *str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(str, ' ');
	if ((!(ft_strncmp(temp[0], "F", ft_strlen(temp[0]))) \
		|| !(ft_strncmp(temp[0], "C", ft_strlen(temp[0])))) \
		&& valid_color2(temp[1]))
		return (1);
	return (0);
}

int	valid_path(char *str)
{
	int		fd;
	int		flag;
	int		len;
	char	**temp;

	fd = -2;
	temp = ft_split(str, ' ');
	len = ft_strlen(temp[0]);
	flag = (!ft_strncmp("NO", temp[0], len) | !ft_strncmp("SO", temp[0], len) \
		| !ft_strncmp("WE", temp[0], len) | !ft_strncmp("EA", temp[0], len));
	if (flag && temp[1])
	{
		fd = open(temp[1], O_RDONLY);
		if (fd == -1)
			return (0);
		close(fd);
	}
	else
		return (0);
	return (1);
}

int	valid_c(char *str)
{
	int	player;

	player = 0;
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == ' ' \
			|| *str == 'N' || *str == 'S' || *str == 'W' || *str == 'E'))
		{
			if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
				player++;
			return (0);
		}
		if (player > 1)
			return (0);
		str++;
	}
	return (1);
}

int	valid_cub(char *str)
{
	if (valid_color(str))
		return (1);
	if (valid_path(str))
		return (2);
	if (valid_c(str))
		return (3);
	return (0);
}
