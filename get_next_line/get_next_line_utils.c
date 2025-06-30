/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:38:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 16:06:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_mem_join(t_mem *mem, char *buf, size_t res)
{
	char	*joined_line;

	if (SIZE_MAX - mem->len < res)
		return (NULL);
	joined_line = (char *)malloc(mem->len + res);
	if (!joined_line)
		return (NULL);
	ft_memcpy(joined_line, mem->line, mem->len);
	ft_memcpy(joined_line + mem->len, buf, res);
	return (joined_line);
}

t_mem	*ft_gnl_new_mem(int fd)
{
	t_mem	*new;

	new = (t_mem *)malloc(sizeof(t_mem));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->line = NULL;
	new->len = 0;
	new->eof = false;
	new->is_newline = false;
	new->newline_offset = 0;
	new->next = NULL;
	return (new);
}

t_mem	*ft_gnl_get_fd_mem(t_mem **lst, int fd)
{
	t_mem	*new;
	t_mem	*current;
	t_mem	*previous;

	if (!lst)
		return (NULL);
	previous = NULL;
	if (!*lst)
	{
		new = ft_gnl_new_mem(fd);
		*lst = new;
		return (new);
	}
	current = *lst;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		previous = current;
		current = current->next;
	}
	new = ft_gnl_new_mem(fd);
	previous->next = new;
	return (new);
}

void	*ft_gnl_mem_delete(t_mem **lst, int fd)
{
	t_mem	*previous;
	t_mem	*current;

	if (!lst || !*lst)
		return (NULL);
	previous = NULL;
	current = *lst;
	while (current->fd != fd)
	{
		previous = current;
		current = current->next;
		if (!current)
			return (NULL);
	}
	free(current->line);
	if (!previous)
		*lst = current->next;
	else
		previous->next = current->next;
	free(current);
	return (NULL);
}
