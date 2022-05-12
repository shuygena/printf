/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:30:31 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 19:41:18 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_determine(char *t, t_format *f, va_list args, int i)
{
	while (!(t[i] > 98 && t[i] < 'y') && t[i] != 88 && t[i] != 37 && t[i] != 0)
	{
		if (t[i] == '-')
			f->minus = t[i - 1];
		if (t[i] == '*' && t[i - 1] == '.')
			f->prec = va_arg(args, int);
		else if (t[i] == '*' && (t[i + 1] == '.' || (t[i + 1] == 'X') ||
					(t[i + 1] >= 'c' && t[i + 1] <= 'x') || t[i + 1] == '%'))
			f->wid = ft_ft((va_arg(args, int)), (*t == 45 || t[i - 1] == 45));
		if (!(t[i] >= '0' && t[i] <= '9'))
			++i;
		ft_initialization(f, (t[i - 1] == '.') * 4);
		if (t[i - 1] == '.')
			while (t[i] >= '0' && t[i] <= '9')
				f->prec = (f->prec) * 10 + ((int)t[i++] - 48);
		while (t[i] == '0')
			f->zero = t[i++];
		while (t[i] >= '0' && t[i] <= '9')
			f->wid = (f->wid) * 10 + ((int)t[i++] - 48);
		ft_initialization(f, 3);
	}
	if ((t[i] >= 'c' && t[i] <= 'x') || (t[i] == 'X') || t[i] == '%')
		f->type = t[i++];
	return (i);
}

void	ft_initialization(t_format *format, int time)
{
	if (time == 3)
	{
		if (format->minus == '%' || format->minus == '0'
				|| format->minus == '-')
			format->wid *= -1;
		if (format->minus == '.')
			format->prec *= -1;
		format->minus = '*';
	}
	else if (time == 1 || time == 2)
	{
		format->wid = 0;
		format->prec = -1;
		format->type = '0';
		if (time == 1)
			format->len = 0;
		format->minus = '+';
		format->zero = ' ';
	}
	else if (time == 4)
		format->prec = 0;
}

int		ft_format_output(t_format *f, int w, int p, va_list args)
{
	if (f->type == 's')
		return (ft_string(va_arg(args, char *), w, p));
	if (f->type == 'c')
		return (ft_ch_out(w, va_arg(args, int)));
	if ((f->type == 'i' || f->type == 'd') && w < 0)
		return (ft_int_align(mod(w), 0, f, va_arg(args, int)));
	if ((f->type == 'i' || f->type == 'd') && w >= 0)
		return (ft_int_out(0, f, va_arg(args, int), f->zero));
	if (f->type == 'u' && w < 0)
		return (ft_un_align(mod(w), 0, f, va_arg(args, unsigned int)));
	if (f->type == 'u' && w >= 0)
		return (ft_un_out(0, f, va_arg(args, unsigned int), f->zero));
	if ((f->type == 'X' || f->type == 'x') && w < 0)
		return (ft_hex_align(mod(w), 0, f, va_arg(args, unsigned int)));
	if ((f->type == 'X' || f->type == 'x') && w >= 0)
		return (ft_hex_out(0, f, va_arg(args, unsigned int), f->zero));
	if (f->type == 'p' && w < 0)
		return (ft_p_align(mod(w), 0, f, va_arg(args, unsigned long)));
	if (f->type == 'p' && w >= 0)
		return (ft_p_out(0, f, va_arg(args, unsigned long)));
	if (f->type == '%')
		return (ft_percent(f));
	return (-2147483648);
}

void	ft_putstr(char *s, t_format *f, va_list args)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			write(1, "%", 1);
			f->len++;
			i += 2;
		}
		else if (s[i] == '%')
		{
			i += 1 + ft_determine(s + i + 1, f, args, 0);
			f->len += ft_format_output(f, f->wid, f->prec, args);
			ft_initialization(f, 2);
		}
		else
		{
			write(1, &(s[i]), 1);
			f->len += 1;
			i++;
		}
	}
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	t_format	format;

	va_start(args, str);
	ft_initialization(&format, 1);
	ft_putstr(str, &format, args);
	va_end(args);
	return (format.len);
}
