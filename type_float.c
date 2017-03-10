/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:27:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/09 15:28:02 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					type_f(va_list *arg, t_flags *flag)
{
	char				*str;
	double				val;

		val = (double)va_arg(*arg, double);
	if (val < 0 || flag->plus == TRUE || flag->space == TRUE)
		flag->width--;
	str = ft_dtoa_base(val, 10, 0);
	precision_float(str, flag, 0);
	str = write_d(str, flag, (int)ft_strlen(str), val);
	final_write(str, flag);
}

void				precision_float(char *str, t_flags *flag, int i)
{
	if (flag->precision >= TRUE)
	{
        while (str[i] != '.' && str[i])
            i++;
        if (flag->precision > TRUE)
            while (str[i] && flag->precision >= TRUE)
            {
                i++;
                flag->precision--;
            }
        str[i] = '\0';
        flag->precision = FALSE;
	}
}
