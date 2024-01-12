/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:56:26 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/22 10:47:57 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(unsigned long long p)
{
	int			cnt;
	t_flag		zflag;

	zflag = init_flag(zflag);
	cnt = 0;
	cnt += prnthex(p, 0, zflag);
	return (cnt);
}

static int	check_pad(t_flag flags, int digits)
{
	int	cnt;

	cnt = 0;
	if (flags.zpad && flags.fwidth > digits)
	{
		cnt += prntstr("0x", init_flag(flags));
		cnt += pad('0', flags.fwidth - digits);
	}
	else if (flags.fwidth && flags.fwidth > digits)
	{
		cnt += pad(' ', flags.fwidth - digits);
		cnt += prntstr("0x", init_flag(flags));
	}
	else
		cnt += prntstr("0x", init_flag(flags));
	return (cnt);
}

int	prntptr(void *ptr, t_flag flags)
{
	unsigned long long	p;
	int					cnt;
	int					digits;

	p = (unsigned long long)ptr;
	digits = hex_count(p) + 2;
	cnt = 0;
	if (flags.left)
	{
		cnt += prntstr("0x", init_flag(flags));
		cnt += putptr(p);
		if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
	}
	else
	{
		cnt += check_pad(flags, digits);
		cnt += putptr(p);
	}
	return (cnt);
}
