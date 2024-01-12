/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:49:24 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 15:10:29 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;
	int		step;

	cnt = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1))
				break ;
			step = 0;
			cnt += check_flag((char *)(format + 1), args, &step);
			format += step + 1;
		}
		else
		{
			cnt += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (cnt);
}
