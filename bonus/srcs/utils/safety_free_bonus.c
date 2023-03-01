/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:33:35 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 17:09:09 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	safety_free(void **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	safety_dimention_free(char ***strs)
{
	char	**temp;

	if (*strs)
	{
		temp = *strs;
		while (*temp != NULL)
		{
			if (*temp)
				free(*temp);
			*temp++ = NULL;
		}
		temp = *strs;
		free(temp);
		temp = NULL;
	}
}
