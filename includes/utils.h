/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:41:14 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:20:24 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

unsigned int	ft_abs(int i);
unsigned long	ft_labs(long i);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strndup(char const *s1, size_t n);
size_t			ft_strnlen(char *s, size_t n);
int				ft_isspace(int c);

#endif
