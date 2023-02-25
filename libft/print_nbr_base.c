/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:13:54 by pjang             #+#    #+#             */
/*   Updated: 2022/09/29 16:15:55 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_nbr_base(long long nbr, char *base, size_t *result)
{
	int	radix;

	radix = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		*result += 1;
		nbr = -nbr;
	}
	if (nbr >= radix)
	{
		print_nbr_base(nbr / radix, base, result);
		print_nbr_base(nbr % radix, base, result);
	}
	if (nbr < radix)
	{
		ft_putchar_fd(*(base + nbr), 1);
		*result += 1;
	}
}
