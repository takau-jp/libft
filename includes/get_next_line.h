/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:38:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 16:33:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifdef __APPLE__
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 16384
#  endif
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE PAGE_SIZE
#  endif
# else
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 4096
#  endif
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 16384
#  endif
# endif

# define FD_TABLE_SIZE 42

typedef struct s_mem
{
	int				fd;
	char			*line;
	size_t			len;
	bool			eof;
	bool			is_newline;
	size_t			newline_offset;
	struct s_mem	*next;
}	t_mem;

char	*get_next_line(int fd);
char	*ft_gnl_mem_join(t_mem *mem, char *buf, size_t res);
t_mem	*ft_gnl_get_fd_mem(t_mem **lst, int fd);
void	*ft_gnl_mem_delete(t_mem **lst, int fd);

#endif
