/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/11 09:23:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
	{
		len++;
		if (len == INT_MAX)
		{
			write(fd, s, len);
			s += len;
			len = 0;
		}
	}
	write(fd, s, len);
}
