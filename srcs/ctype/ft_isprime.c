/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:20:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/29 20:20:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	next_large_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	n;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	if (!(nb % 2) || !(nb % 3) || !(nb % 5) || !(nb % 7))
		return (0);
	sqrt = next_large_sqrt(nb);
	n = 11;
	while (n <= sqrt)
	{
		if (nb % n == 0)
			return (0);
		n += 2;
	}
	return (1);
}

static int	next_large_sqrt(int nb)
{
	int	n;

	n = 1;
	while (nb / n > n)
		n++;
	return (n);
}
