/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:04:33 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:15:58 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_ptr_base(unsigned long long nbr, char *base, size_t *result)
{
	unsigned long long	radix;

	radix = ft_strlen(base);
	if (nbr >= radix)
	{
		print_ptr_base(nbr / radix, base, result);
		print_ptr_base(nbr % radix, base, result);
	}
	if (nbr < radix)
	{
		ft_putchar_fd(*(base + nbr), 1);
		*result += 1;
	}
}

void	print_ptr(unsigned long ptr, size_t *result)
{
	write(1, "0x", 2);
	*result += 2;
	print_ptr_base(ptr, HEXA_DECIMAL_LOW, result);
}
