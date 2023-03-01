/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:54:18 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 14:00:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	getsize(const char *s1, const char *set, int len, int *start)
{
	int	end;

	end = 0;
	while (s1[*start] && is_set(s1[*start], set))
		*start += 1;
	end = len - 1;
	while (end >= 0 && is_set(s1[end], set))
		end--;
	if (*start == len)
		return (0);
	return (end - *start + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		start;
	int		size;
	char	*buf;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	size = getsize(s1, set, len, &start);
	if (!size)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	buf = result;
	size = (size + start - 1);
	while (start <= size)
		*buf++ = s1[start++];
	*buf = '\0';
	return (result);
}
