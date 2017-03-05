/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:34:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/01 12:42:03 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 0
# define FALSE -1

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			sharp;
	int			zero;
	int			hyphen;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			mod_hh;
	int			mod_h;
	int			mod_l;
	int			mod_ll;
	int			mod_j;
	int			mod_z;
	size_t		len;
}				t_flags;

int				determine_type1(char type, va_list *arg, t_flags *flag);
int				determine_type2(char type, va_list *arg, t_flags *flag);
const char		*det_invalid(const char *format, va_list *arg, t_flags *flag);
const char		*det_arg(const char *format, va_list *arg, t_flags *flag);
int				ft_printf(const char *format, ...);
void			init_all_false(t_flags *flag);
void			init_flags(t_flags *flag, char c);
const char		*init_width(t_flags *flag, const char *format, va_list *arg);
const char		*init_prec(t_flags *flag, const char *format, va_list *arg);
const char		*init_mods_size(t_flags *flag, const char *format);
void			type_x(va_list *arg, t_flags *flag, int fg);
void			to_type_X(char *str);
void            case_sharp_x(char **str);
void			type_p(va_list *arg, t_flags *flag);
void			type_o(va_list *arg, t_flags *flag);
void            case_sharp_o(char **str);
void			type_d_i(va_list *arg, t_flags *flag);
char			*check_spaced(char *str, t_flags *flag, long long val);
char			*write_d(char *str, t_flags *flag, int len, long long val);
void			type_u(va_list *arg, t_flags *flag);
void			type_c(va_list *arg, t_flags *flag, unsigned char in);
void			type_lc(va_list *arg, t_flags *flag);
void			write_c(unsigned char c, t_flags *flag, int n);
char            *convert_wchar(int i);
unsigned char	*filwidth_c(t_flags *flag, unsigned char *s, unsigned char c);
void			write_s(char *str, t_flags *flag, int len);
void			type_s(va_list *arg, t_flags *flag, int i);
void			type_S(va_list *arg, t_flags *flag);
void			write_S(char **str, t_flags *flag, int len);
int         	ft_len_all(char **str);
int				ft_is_end_spec(char f);
int				valide_flags(const char *fmt, int i);
char		    *main_write(char *str, t_flags *flag, int len);
char			*ft_filwidth(t_flags *flag, char *s, char c);
void            final_write(char *str, t_flags *flag);
char			*ft_unsigned_atol(unsigned long long value, unsigned long long base);
char			*ft_atol_base(long long value, long long base);
#endif
