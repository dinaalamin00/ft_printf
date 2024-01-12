/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:55:30 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/18 10:03:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prntchar(char c, t_flag flags)
{
	int	cnt;

	cnt = 0;
	if (flags.left)
	{
		cnt += write(1, &c, 1);
		cnt += pad(' ', flags.fwidth - 1);
	}
	else
	{
		if (flags.fwidth)
			cnt += pad(' ', flags.fwidth - 1);
		cnt += write(1, &c, 1);
	}
	return (cnt);
}
