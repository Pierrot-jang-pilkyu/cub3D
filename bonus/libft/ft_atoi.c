/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:38:12 by pjang             #+#    #+#             */
/*   Updated: 2022/04/18 13:43:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(unsigned char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	val;

	sign = 1;
	result = 0;
	while (*str && is_space((unsigned char)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	val = 9223372036854775807;
	if (result > val && sign == 1)
		return (-1);
	if (result > (val + 1) && sign == -1)
		return (0);
	return (((int)result * sign));
}
