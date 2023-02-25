/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:07:49 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:16:41 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	idx;
	size_t	result;
	va_list	ap;

	idx = 0;
	result = 0;
	va_start(ap, format);
	while (idx != ft_strlen(format))
	{
		if (format[idx] == '%')
		{
			idx++;
			if (format[idx] != '\0' )
				put_format(format, &result, &idx, &ap);
		}
		while (format[idx] && format[idx] != '%')
		{
			print_char(format[idx], &result);
			idx++;
		}
	}
	va_end(ap);
	return (result);
}
