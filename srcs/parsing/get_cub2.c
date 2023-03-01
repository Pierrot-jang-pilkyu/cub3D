/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:04:49 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 19:01:04 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_cub2(int flag, t_map *map, char *temp)
{
	int	ret;

	ret = 0;
	if (flag == 1 && get_color(temp, map))
		ret = 1;
	else if (flag == 2 && get_path(temp, map))
		ret = 1;
	else if (flag == 3 && get_map(temp, map))
		ret = 1;
	else if (flag == 0)
		ret = 1;
	return (ret);
}
