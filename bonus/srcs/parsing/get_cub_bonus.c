/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:19:00 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 17:04:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	get_color(char *str, t_map *map)
{
	int		i;
	int		ret;
	char	**temp1;
	char	**temp2;

	i = -1;
	ret = 1;
	temp1 = ft_split(str, ' ');
	temp2 = ft_split(temp1[1], ',');
	if (*str == 'F')
	{
		while (++i < 3)
			map->floor[i] = ft_atoi(temp2[i]);
		ret = 0;
	}
	else if (*str == 'C')
	{
		while (++i < 3)
			map->ceil[i] = ft_atoi(temp2[i]);
		ret = 0;
	}
	safety_dimention_free(&temp1);
	safety_dimention_free(&temp2);
	return (ret);
}

int	get_path(char *str, t_map *map)
{
	int		ret;
	char	**temp;

	ret = (!ft_strncmp("NO", str, 2) | !ft_strncmp("SO", str, 2) \
		| !ft_strncmp("WE", str, 2) | !ft_strncmp("EA", str, 2));
	temp = ft_split(str, ' ');
	if (!ft_strncmp("NO", str, 2))
		map->texture[N].path = ft_strdup(temp[1]);
	if (!ft_strncmp("SO", str, 2))
		map->texture[S].path = ft_strdup(temp[1]);
	if (!ft_strncmp("WE", str, 2))
		map->texture[W].path = ft_strdup(temp[1]);
	if (!ft_strncmp("EA", str, 2))
		map->texture[E].path = ft_strdup(temp[1]);
	safety_dimention_free(&temp);
	return (!ret);
}

int	get_map(char *str, t_map *map)
{
	char	*temp;
	t_list	*newlst;

	temp = ft_strdup(str);
	if (!temp)
		return (1);
	newlst = ft_lstnew(temp);
	if (!newlst)
	{
		safety_free((void **)&temp);
		return (1);
	}
	ft_lstadd_back(&map->lst_map, newlst);
	map->height++;
	map->width = ft_max(map->width, ft_strlen(temp));
	return (0);
}

char	*get_notnl(int fd)
{
	int		len;
	char	*temp;
	char	*res;

	temp = get_next_line(fd);
	if (!temp)
		return (NULL);
	len = ft_strlen(temp);
	if (temp[len - 1] == '\n')
		res = ft_substr(temp, 0, len - 1);
	else
		res = ft_strdup(temp);
	if (!res)
	{
		safety_free((void **)&temp);
		return (NULL);
	}
	safety_free((void **)&temp);
	return (res);
}

int	get_cub(int fd, t_map *map)
{
	int		ret;
	int		flag;
	char	*temp;

	ret = 0;
	while (777)
	{
		temp = get_notnl(fd);
		if (!temp)
			break ;
		if (*temp == '\0')
		{
			safety_free((void **)&temp);
			continue ;
		}
		flag = valid_cub(temp);
		ret = get_cub2(flag, map, temp);
		safety_free((void **)&temp);
	}
	if (!ret && get_maze(map))
		ret = 1;
	return (ret);
}
