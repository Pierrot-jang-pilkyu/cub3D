/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:46:00 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 13:56:48 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_pow(int n, int power)
{
	long long int	result;

	if (power >= 0)
	{
		result = 1;
		while (power-- > 0)
			result *= n;
	}
	else
		return (0);
	return (result);
}

static int	digits_of(long long int n)
{
	int	result;
	int	power;

	result = 0;
	power = 0;
	while (n / ft_pow(10, power++))
		result++;
	return (result);
}

static void	n_is_zero(int n, char **buf)
{
	if (n == 0)
	{
		*buf[0] = '0';
		*buf += 1;
	}
}

char	*ft_itoa(int n)
{
	char			*buf;
	char			*result;
	int				len;
	long long int	tmp;

	tmp = n;
	len = digits_of(tmp);
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	buf = result;
	n_is_zero(n, &buf);
	if (tmp < 0)
	{
		tmp = -tmp;
		*buf = '-';
		buf++;
	}
	while (--len >= 0)
	{
		*buf++ = (tmp / ft_pow(10, len) + '0');
		tmp = tmp % ft_pow(10, len);
	}
	*buf = '\0';
	return (result);
}
