/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:50:43 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:44:14 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*buf;
	char	*dst;

	if (!s1)
		return (NULL);
	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	buf = dst;
	while (*s1)
		*buf++ = *s1++;
	*buf = '\0';
	return (dst);
}
