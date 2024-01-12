/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:44:53 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/22 13:33:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int	left;
	int	zpad;
	int	fwidth;
	int	hash;
	int	sign;
	int	space;
}t_flag;

int		ft_printf(const char *format, ...);
int		check_flag(char *f, va_list args, int *step);
int		check_spec(char *f, va_list args, t_flag flags);
int		prntchar( char c, t_flag flags);
int		prntstr(char *str, t_flag flags);
int		prntnbr(int n, t_flag flags);
int		prntun(unsigned int n, t_flag flags);
int		prnthex(unsigned long long n, int c, t_flag flags);
int		prntptr(void *p, t_flag flags);
int		prntpercent(t_flag flags);

t_flag	init_flag(t_flag flag);
int		pad(char c, int width);
int		int_count(int n);
int		un_count(unsigned int n);
int		char_count(char *s);
int		hex_count(unsigned long long n);
#endif