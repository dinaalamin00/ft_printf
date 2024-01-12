/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:19:21 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 14:31:49 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_spec(char *f, va_list args, t_flag flags)
{
	int	cnt;

	cnt = 0;
	if (*f == 'c')
		cnt += prntchar(va_arg(args, int), flags);
	else if (*f == 's')
		cnt += prntstr(va_arg(args, char *), flags);
	else if (*f == 'd' || *f == 'i')
		cnt += prntnbr(va_arg(args, int), flags);
	else if (*f == 'u')
		cnt += prntun(va_arg(args, unsigned int), flags);
	else if (*f == 'x')
		cnt += prnthex(va_arg(args, unsigned int), 0, flags);
	else if (*f == 'X')
		cnt += prnthex(va_arg(args, unsigned int), 1, flags);
	else if (*f == 'p')
		cnt += prntptr(va_arg(args, void *), flags);
	else if (*f == '%')
		cnt += prntpercent(flags);
	else
		cnt += write(1, f, 1);
	return (cnt);
}
