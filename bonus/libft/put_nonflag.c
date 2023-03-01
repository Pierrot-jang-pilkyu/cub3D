/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nonflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:01:58 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:16:09 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_nonflag(char c, va_list *ap, size_t *result)
{
	if (c == 'c')
		print_char(va_arg(*ap, int), result);
	else if (c == 's')
		print_str(va_arg(*ap, char *), result);
	else if (c == 'p')
		print_ptr(va_arg(*ap, unsigned long), result);
	else if (c == 'd' || c == 'i')
		print_nbr_base(va_arg(*ap, int), DECIMAL, result);
	else if (c == 'u')
		print_nbr_base((long long)va_arg(*ap, unsigned int), DECIMAL, result);
	else if (c == 'x')
		print_nbr_base(va_arg(*ap, unsigned int), HEXA_DECIMAL_LOW, result);
	else if (c == 'X')
		print_nbr_base(va_arg(*ap, unsigned int), HEXA_DECIMAL_UP, result);
	else if (c == '%')
		print_char('%', result);
}
