/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:25:47 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/19 14:54:57 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prntpercent(t_flag flags)
{
	int	cnt;

	cnt = 0;
	if (flags.left)
	{
		cnt += write(1, "%", 1);
		cnt += pad(' ', flags.fwidth - 1);
	}
	else
	{
		if (flags.fwidth)
			cnt += pad(' ', flags.fwidth - 1);
		cnt += write(1, "%", 1);
	}
	return (cnt);
}
