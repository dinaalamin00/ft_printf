/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:04:29 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/18 14:38:00 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	init_flag(t_flag flag)
{
	flag.fwidth = 0;
	flag.left = 0;
	flag.zpad = 0;
	flag.hash = 0;
	flag.sign = 0;
	flag.space = 0;
	return (flag);
}
