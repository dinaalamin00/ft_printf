/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:56:32 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/22 13:38:02 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(int n, t_flag flags)
{
	int		cnt;
	t_flag	zflag;

	zflag = init_flag(zflag);
	cnt = 0;
	if (flags.sign && n >= 0 && !flags.zpad && !flags.left)
		cnt += write(1, "+", 1);
	else if (flags.space && n >= 0 && !flags.zpad && !flags.left)
		cnt += write(1, " ", 1);
	if (n == -2147483648)
	{
		cnt += prntstr("-2147483648", zflag);
		return (cnt);
	}
	if (n < 0)
	{
		cnt += prntchar('-', zflag);
		n = -n;
	}
	if (n >= 10)
		cnt += prntnbr(n / 10, zflag);
	cnt += prntchar((n % 10) + 48, zflag);
	return (cnt);
}

static int	digcnt(int n, t_flag flags)
{
	int	d;

	d = 0;
	if (flags.sign || flags.space)
	{
		d++;
		if (flags.sign && n < 0)
			return (d);
	}
	if (n < 0)
		d++;
	return (d);
}

static int	check_sign(int *n, t_flag flags, int digits)
{
	int	cnt;

	cnt = 0;
	if ((*n) < 0)
	{
		cnt += write(1, "-", 1);
		cnt += pad('0', flags.fwidth - digits);
		if ((*n) == -2147483648)
		{
			cnt += write(1, "2", 1);
			(*n) = 147483648;
		}
		else
			(*n) = -(*n);
	}
	else
	{
		if (flags.sign && n >= 0)
			cnt += write(1, "+", 1);
		else if (flags.space && n >= 0)
			cnt += write(1, " ", 1);
		cnt += pad('0', flags.fwidth - digits);
	}
	return (cnt);
}

int	prntnbr(int n, t_flag flags)
{
	int	digits;
	int	cnt;

	digits = int_count(n) + digcnt(n, flags);
	cnt = 0;
	if (flags.left)
	{
		if (flags.sign && n >= 0)
			cnt += write(1, "+", 1);
		else if (flags.space && n >= 0)
			cnt += write(1, " ", 1);
		cnt += putnbr (n, flags);
		if (flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
	}
	else
	{
		if (flags.zpad && flags.fwidth > digits)
			cnt += check_sign(&n, flags, digits);
		else if (flags.fwidth && flags.fwidth > digits)
			cnt += pad(' ', flags.fwidth - digits);
		cnt += putnbr (n, flags);
	}
	return (cnt);
}
