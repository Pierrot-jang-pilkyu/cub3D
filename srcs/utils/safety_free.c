/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:33:35 by pjang             #+#    #+#             */
/*   Updated: 2023/02/24 17:36:54 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	safety_free(void **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	safety_dimention_free(char **strs)
{
	char	**temp;

	if (strs)
	{
		temp = strs;
		while (*strs != NULL)
		{
			if (*strs)
				free(*strs);
			*strs++ = NULL;
		}
		strs = temp;
		free(strs);
		strs = NULL;
	}
}
