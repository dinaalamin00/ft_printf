/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:55:50 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 11:09:55 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_flag(char c, t_flag *flags)
{
	if (c == '-')
		flags->left = 1;
	else if (c == '0')
		flags->zpad = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '+')
		flags->sign = 1;
	else if (c == ' ')
		flags->space = 1;
}

int	check_flag(char *f, va_list args, int *step)
{
	t_flag	flags;
	int		cnt;

	flags = init_flag(flags);
	cnt = 0;
	while ((*f == '-') || (*f == '0') || *f == '#' || *f == '+' || *f == ' ')
	{
		add_flag(*f, &flags);
		f++;
		(*step)++;
	}
	while (*f >= '0' && *f <= '9')
	{
		flags.fwidth = flags.fwidth * 10 + *f - 48;
		f++;
		(*step)++;
	}
	cnt += check_spec(f, args, flags);
	return (cnt);
}
