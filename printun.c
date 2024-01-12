/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:55:38 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 12:50:37 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnun(unsigned int n)
{
	int		cnt;
	t_flag	zflag;

	zflag = init_flag(zflag);
	cnt = 0;
	if (n >= 10)
		cnt += putnun(n / 10);
	cnt += prntchar((n % 10) + 48, zflag);
	return (cnt);
}

int	prntun(unsigned int n, t_flag flags)
{
	int	digits;
	int	cnt;

	digits = un_count(n);
	cnt = 0;
	if (flags.left)
	{
		cnt += putnun (n);
		if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
	}
	else
	{
		if (flags.zpad && flags.fwidth > digits)
			cnt += pad('0', flags.fwidth - digits);
		else if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
		cnt += putnun (n);
	}
	return (cnt);
}
