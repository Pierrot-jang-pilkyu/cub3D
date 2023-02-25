/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:50:25 by pjang             #+#    #+#             */
/*   Updated: 2022/12/04 18:23:15 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_strs(const char *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
			result++;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

int	get_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	*get_word(const char *s, char c)
{
	char	*buf;
	char	*word;

	word = (char *)malloc(sizeof(char) * (get_len(s, c) + 1));
	if (!word)
		return (NULL);
	buf = word;
	while (*s && *s != c)
	{
		*buf++ = *s++;
	}
	*buf = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		strs;
	char	**buf;
	char	**split;

	strs = get_strs(s, c);
	split = (char **)malloc(sizeof(char *) * (strs + 1));
	if (!split)
		return (NULL);
	buf = split;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
		{
			*buf = get_word(s, c);
			if (!(*buf))
				return (NULL);
			buf++;
		}
		while (*s && *s != c)
			s++;
	}
	*buf = 0;
	return (split);
}
