/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent_darwin_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:40:06 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:35:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_conv_percent(t_fprintf_ctx *ctx)
{
	if (!ctx->width_flags)
		ft_print_space_width(ctx, 1);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, 1);
	ft_fprint_char(ctx, '%');
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
}
