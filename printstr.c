/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:56:03 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 11:11:29 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putstr(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		cnt += write(1, &str[i], 1);
		i++;
	}
	return (cnt);
}

int	prntstr(char *str, t_flag flags)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (flags.left)
	{
		cnt += putstr(str);
		if (flags.fwidth && flags.fwidth > char_count(str))
			cnt += pad(' ', flags.fwidth - char_count(str));
	}
	else
	{
		if (flags.fwidth && flags.fwidth > char_count(str))
			cnt += pad(' ', flags.fwidth - char_count(str));
		cnt += putstr(str);
	}
	return (cnt);
}
