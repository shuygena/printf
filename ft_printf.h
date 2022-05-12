/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:40:52 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 19:42:27 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_format
{
	int				wid;
	int				prec;
	int				len;
	char			type;
	char			minus;
	char			zero;
}					t_format;

int					ft_printf(char *str, ...);
void				ft_putstr(char *s, t_format *f, va_list args);
int					ft_format_output(t_format *f, int w, int p, va_list args);
void				ft_initialization(t_format *format, int time);
int					ft_determine(char *types, t_format *f, va_list args, int i);
int					ft_ch_out(int wid, char c);
int					ft_str_align(int wid, int prec, char *s);
int					ft_str_out(int wid, int prec, char *s);
int					ft_strlen(char *str);
unsigned int		mod(int n);
int					ft_max(int a, int b);
int					ft_digit_len(unsigned int n, unsigned int minus);
int					ft_int_align(int w, int i, t_format *f, int n);
int					ft_int_out(int i, t_format *f, int n, char z);
void				ft_putnbr(unsigned int num, int zero_count, int neg);
int					ft_un_out(int i, t_format *f, unsigned int n, char z);
int					ft_un_align(int w, int i, t_format *f, unsigned int n);
int					ft_hex_len(unsigned long long num);
unsigned long long	ft_pow(unsigned long num, int len);
void				ft_put_hex(unsigned long long num, int len, char low_up,
					int z);
int					ft_string(char *s, int w, int p);
int					ft_hex_out(int i, t_format *f, unsigned int n, char z);
int					ft_hex_align(int w, int i, t_format *f, unsigned int n);
int					ft_p_align(int w, int i, t_format *f, unsigned long long n);
int					ft_p_out(int i, t_format *f, unsigned long long n);
int					ft_ft(int wid, int minus);
int					ft_percent(t_format *f);

#endif
