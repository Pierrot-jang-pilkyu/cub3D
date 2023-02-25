/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:38:32 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 13:38:35 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == 0 || size == 0)
		return (malloc((0)));
	if (size > SIZE_MAX / count)
		return (malloc(SIZE_MAX));
	result = malloc(count * size);
	if (result)
		ft_bzero(result, count * size);
	return (result);
}
