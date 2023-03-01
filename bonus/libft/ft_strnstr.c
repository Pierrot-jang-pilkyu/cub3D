/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:53:43 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 13:59:37 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len-- > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && i <= len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
