/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:56:45 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 13:37:04 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthash(int n, int c, t_flag flags)
{
	int		cnt;
	t_flag	zflag;

	zflag = init_flag(zflag);
	cnt = 0;
	if (flags.hash && n != 0)
	{
		if (c == 0)
			cnt += prntstr("0x", zflag);
		else
			cnt += prntstr("0X", zflag);
	}
	return (cnt);
}

static int	puthex(unsigned long long n, int c, t_flag flags, int digits)
{
	int		cnt;
	char	*lh;
	char	*uh;
	t_flag	zflag;

	zflag = init_flag(zflag);
	lh = "0123456789abcdef";
	uh = "0123456789ABCDEF";
	cnt = 0;
	if (!(flags.zpad && flags.fwidth > digits))
		cnt += puthash(n, c, flags);
	if (n >= 16)
		cnt += prnthex(n / 16, c, zflag);
	if (c == 0)
		cnt += write(1, &lh[(n % 16)], 1);
	else
		cnt += write(1, &uh[(n % 16)], 1);
	return (cnt);
}

int	prnthex(unsigned long long n, int c, t_flag flags)
{
	int		digits;
	int		cnt;

	digits = hex_count(n) + (2 * flags.hash);
	cnt = 0;
	if (flags.left)
	{
		cnt += puthash(n, c, flags);
		cnt += puthex(n, c, flags, digits);
		if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
	}
	else
	{
		if (flags.zpad && flags.fwidth > digits)
		{
			cnt += puthash(n, c, flags);
			cnt += pad('0', flags.fwidth - digits);
		}
		else if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
		cnt += puthex(n, c, flags, digits);
	}
	return (cnt);
}
