/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_utils_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:17:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:35:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_print_space_width(t_fprintf_ctx *ctx, size_t len)
{
	char	*buf;
	size_t	buf_size;

	if (ctx->width <= 0 || (size_t)ctx->width <= len)
		return ;
	buf_size = ctx->width - len;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, ' ', buf_size);
	ft_fprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_zero_width(t_fprintf_ctx *ctx, size_t len)
{
	char	*buf;
	size_t	buf_size;

	if (ctx->width <= 0 || (size_t)ctx->width <= len)
		return ;
	buf_size = ctx->width - len;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, '0', buf_size);
	ft_fprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_padding(t_fprintf_ctx *ctx, size_t padding)
{
	char	*buf;
	size_t	buf_size;

	if (padding == 0)
		return ;
	buf_size = padding;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, '0', buf_size);
	ft_fprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_sign(t_fprintf_ctx *ctx, bool is_negative)
{
	if (is_negative)
		ft_fprint_char(ctx, '-');
	else if (!is_negative && ctx->sign_flags == '+')
		ft_fprint_char(ctx, '+');
	else if (!is_negative && ctx->sign_flags == ' ')
		ft_fprint_char(ctx, ' ');
}
