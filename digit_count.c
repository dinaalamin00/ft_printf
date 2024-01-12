/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:48:58 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/20 12:59:44 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_count(int n)
{
	int	cnt;

	cnt = 1;
	while (n / 10 != 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

int	un_count(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n / 10 != 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

int	hex_count(unsigned long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		cnt++;
	}
	return (cnt);
}

int	char_count(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
