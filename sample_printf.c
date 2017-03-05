/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:53 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/01 15:15:34 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void simple_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

	while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf( "%d\n", i ) ;
        } else if (*fmt == 'c') {
            int c = va_arg(args, int);
            printf( "%c\n", (char)c ) ;
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf( "%f\n", d ) ;
        }
        ++fmt;
    }

	va_end(args);
}

int main()
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5); 
}
