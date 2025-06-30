/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c_darwin_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:24:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 15:10:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_conv_c(va_list *ap, t_fprintf_ctx *ctx)
{
	int	c;

	if (!ft_strcmp(ctx->length, "l"))
	{
		ft_conv_lc(ap, ctx);
		return ;
	}
	c = va_arg(*ap, int);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, 1);
	else if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, 1);
	ft_fprint_char(ctx, c);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
}
