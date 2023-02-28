/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cub2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:18:39 by pjang             #+#    #+#             */
/*   Updated: 2023/02/28 19:21:28 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_color3(char **temp, int i)
{
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

int	valid_color2(char *str)
{
	int		ret;
	int		i;
	char	**temp;

	if (str == NULL)
		return (0);
	temp = ft_split(str, ',');
	i = 0;
	while (temp[i] != NULL)
		i++;
	ret = valid_color3(temp, i);
	safety_dimention_free(&temp);
	return (ret);
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
	{
		safety_dimention_free(&temp);
		return (1);
	}
	safety_dimention_free(&temp);
	return (0);
}
