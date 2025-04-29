/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:41:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/29 17:50:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n);

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	un;
	int				digits;

	digits = count_digits(n);
	num = (char *)malloc(digits + 1);
	if (!num)
		return (NULL);
	num[digits] = '\0';
	un = n;
	if (n < 0)
		un = ~n + 1;
	while (digits--)
	{
		num[digits] = (un % 10) + '0';
		if (n < 0 && digits == 1)
		{
			num[0] = '-';
			break ;
		}
		un /= 10;
	}
	return (num);
}

static int	count_digits(int n)
{
	int	digits;

	if (!n)
		return (1);
	digits = 0;
	if (n < 0)
		digits = 1;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
