/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:11:47 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:16:02 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(char *str, size_t *result)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*result += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*result += ft_strlen(str);
}
