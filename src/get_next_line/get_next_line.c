/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 00:47:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/17 13:29:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

static bool	read_file(int fd, t_buf *buf);
static bool	append_to_next_line(t_next_line *next_line, char c);

char	*get_next_line(int fd)
{
	static t_buf	buf;
	t_next_line		next_line;

	ft_bzero(&next_line, sizeof(t_next_line));
	while (true)
	{
		if (!read_file(fd, &buf))
			break ;
		if (buf.read_bytes == 0)
			return (next_line.data);
		if (!append_to_next_line(&next_line, buf.data[buf.used_bytes++]))
			break ;
		if (buf.data[buf.used_bytes - 1] == '\n' \
			|| buf.data[buf.used_bytes - 1] == '\0')
		{
			return (next_line.data);
		}
	}
	free(next_line.data);
	buf.read_bytes = 0;
	buf.used_bytes = 0;
	return (NULL);
}

static bool	read_file(int fd, t_buf *buf)
{
	ssize_t	res;

	if (buf->used_bytes == buf->read_bytes)
	{
		res = read(fd, buf->data, BUFFER_SIZE);
		if (res < 0)
			return (false);
		buf->read_bytes = res;
		buf->used_bytes = 0;
	}
	return (true);
}

static bool	append_to_next_line(t_next_line *next_line, char c)
{
	if (next_line->allocated_size != 0 && c == '\0')
		return (true);
	if (next_line->allocated_size == 0 \
		|| next_line->len + 1 == next_line->allocated_size)
	{
		if (next_line->allocated_size == 0 && c == '\0')
			next_line->allocated_size = 1;
		else if (next_line->allocated_size == 0)
			next_line->allocated_size = 2;
		else if (next_line->allocated_size < 1024)
			next_line->allocated_size = next_line->allocated_size * 2;
		else
			next_line->allocated_size = next_line->allocated_size + 1024;
		next_line->data = ft_reallocf(\
			next_line->data, next_line->len, next_line->allocated_size);
		if (next_line->data == NULL)
			return (false);
	}
	if (c != '\0')
		next_line->data[next_line->len++] = c;
	next_line->data[next_line->len] = '\0';
	return (true);
}
