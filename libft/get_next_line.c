/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:03:31 by pjang             #+#    #+#             */
/*   Updated: 2022/09/23 06:11:22 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	safe_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	refresh(long long mode, char **str, char **buffer, char *temp)
{
	long long	idx;

	if (mode == 1)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		*str = ft_strjoin(temp, *buffer);
		safe_free(&temp);
	}
	if (mode == 2)
	{
		temp = ft_strdup(*str);
		safe_free(str);
		idx = get_index(temp);
		*str = ft_substr(temp, idx + 1, ft_strlen(temp) - idx);
		safe_free(&temp);
	}
}

void	division_str(char **str, int fd)
{
	char		*buffer;
	long long	f_len;

	if (*str == 0x00)
		*str = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (2));
	if (!buffer)
		return ;
	*buffer = '\0';
	while (1)
	{
		f_len = read(fd, buffer, 1);
		if (f_len == 0 || f_len == -1)
			break ;
		buffer[f_len] = '\0';
		refresh(1, str, &buffer, NULL);
		if (get_index(buffer) != -1)
			break ;
	}
	if (f_len == -1 || (f_len == 0 && **str == '\0'))
		safe_free(str);
	safe_free(&buffer);
}

char	*get_result(char **str)
{
	char		*temp;
	long long	idx;

	temp = NULL;
	if (*str)
	{
		idx = get_index(*str);
		if (idx != -1)
		{
			temp = ft_substr(*str, 0, idx + 1);
			refresh(2, str, NULL, NULL);
		}
		else
		{
			temp = ft_strdup(*str);
			safe_free(str);
		}
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*temp;

	if (fd >= OPEN_MAX || fd < 0)
		return (NULL);
	temp = NULL;
	division_str(&str[fd], fd);
	if (str[fd] && *str[fd] == '\0')
		return (NULL);
	if (str[fd])
		temp = get_result(&str[fd]);
	return (temp);
}
