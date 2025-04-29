/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:40:26 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/29 19:55:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static bool	is_long_overflow(long *num, int sign, int n);

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while (ft_isdigit(*nptr))
	{
		if (is_long_overflow(&num, sign, (*nptr - '0')))
			return (num);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

static bool	is_long_overflow(long *num, int sign, int n)
{
	long	limit;

	limit = (long []){LONG_MIN, LONG_MAX}[sign == 1];
	if (*num > LONG_MAX / 10 || \
		(*num == LONG_MAX / 10 && (int)(ft_labs(limit) % 10) <= n))
	{
		*num = limit;
		return (true);
	}
	return (false);
}
