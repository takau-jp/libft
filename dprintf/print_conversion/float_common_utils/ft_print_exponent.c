/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exponent_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:05:28 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:32:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_print_num(t_dprintf_ctx *ctx, int num);

void	ft_print_exponent(t_dprintf_ctx *ctx, int decimal_exponent)
{
	if (ctx->conv == 'e' || ctx->conv == 'g')
		ft_fprint_char(ctx, 'e');
	else if (ctx->conv == 'E' || ctx->conv == 'G')
		ft_fprint_char(ctx, 'E');
	if (decimal_exponent >= 0)
		ft_fprint_char(ctx, '+');
	else
		ft_fprint_char(ctx, '-');
	if (-10 < decimal_exponent && decimal_exponent < 10)
		ft_fprint_char(ctx, '0');
	ft_print_num(ctx, decimal_exponent);
}

void	ft_print_exponent_hex(t_dprintf_ctx *ctx, int exp)
{
	if (ctx->conv == 'a')
		ft_fprint_char(ctx, 'p');
	else if (ctx->conv == 'A')
		ft_fprint_char(ctx, 'P');
	if (exp >= 0)
		ft_fprint_char(ctx, '+');
	else
		ft_fprint_char(ctx, '-');
	ft_print_num(ctx, exp);
}

static void	ft_print_num(t_dprintf_ctx *ctx, int num)
{
	unsigned int	n;

	n = num;
	if (num < 0)
		n = ~num + 1;
	if (n >= 10)
		ft_print_num(ctx, n / 10);
	ft_fprint_char(ctx, "0123456789"[n % 10]);
}
