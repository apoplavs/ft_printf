/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:56:37 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/09 14:57:30 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft(unsigned long long v, unsigned long long b, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (v >= b)
		ft(v / b, b, str, i);
	str[(*i)++] = tmp[(v % b)];
}

char		*ft_unsigned_atol(unsigned long long value, unsigned long long base)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	ft(value, base, str, &i);
	return (str);
}

static void	funct(long long v, long long b, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (v <= -b || v >= b)
		funct(v / b, b, str, i);
	str[(*i)++] = tmp[(v % b) < 0 ? -(v % b) : (v % b)];
}

char		*ft_atol_base(long long value, long long base)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(24);
	funct(value, base, str, &i);
	return (str);
}
