/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:25:36 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 19:34:42 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_out(int i, t_format *f, int n, char z)
{
	int len;

	if (n == 0 && f->prec == 0)
	{
		while (i++ < f->wid)
			write(1, " ", 1);
		return (f->wid);
	}
	len = ft_digit_len((mod(n)), (n < 0));
	if ((z != '0' || f->prec >= 0) && f->wid > f->prec && f->wid > len)
	{
		while (i++ < f->wid - (ft_max(f->prec, len)) -
				(f->prec >= len && n < 0))
			write(1, " ", 1);
		ft_putnbr(mod(n), (f->prec - len + (n < 0)), (n < 0));
		return (f->wid);
	}
	if (f->wid > len && z == 48 && f->prec < 0)
	{
		ft_putnbr(mod(n), (f->wid - len), (n < 0));
		return (f->wid);
	}
	ft_putnbr(mod(n), (f->prec - len + (n < 0)), (n < 0));
	return (ft_max(f->prec, len) + (f->prec >= len && n < 0));
}

int		ft_int_align(int w, int i, t_format *f, int n)
{
	int len;

	if (f->prec == 0 && n == 0)
	{
		while (i++ < w)
			write(1, " ", 1);
		return (w);
	}
	len = ft_digit_len((mod(n)), (n < 0));
	ft_putnbr(mod(n), (f->prec - len + (n < 0)), (n < 0));
	if (w > f->prec && w > len)
	{
		while (i++ < (w - (ft_max(f->prec, len)) - (f->prec >= len && n < 0)))
			write(1, " ", 1);
		return (w);
	}
	return (ft_max(f->prec, len) + (f->prec >= len && n < 0));
}

int		ft_un_out(int i, t_format *f, unsigned int n, char z)
{
	int len;

	if (n == 0 && f->prec == 0)
	{
		while (i++ < f->wid)
			write(1, " ", 1);
		return (f->wid);
	}
	len = ft_digit_len((n), 0);
	if ((z != '0' || f->prec >= 0) && f->wid > f->prec && f->wid > len)
	{
		while (i++ < f->wid - (ft_max(f->prec, len)))
			write(1, " ", 1);
		ft_putnbr(n, (f->prec - len), 0);
		return (f->wid);
	}
	if (f->wid > len && z == 48 && f->prec < 0)
	{
		ft_putnbr(n, (f->wid - len), 0);
		return (f->wid);
	}
	ft_putnbr(n, (f->prec - len), 0);
	return (ft_max(f->prec, len));
}

int		ft_un_align(int w, int i, t_format *f, unsigned int n)
{
	int len;

	if (f->prec == 0 && n == 0)
	{
		while (i++ < w)
			write(1, " ", 1);
		return (w);
	}
	len = ft_digit_len(n, 0);
	ft_putnbr(n, (f->prec - len), 0);
	if (w > f->prec && w > len)
	{
		while (i++ < (w - (ft_max(f->prec, len))))
			write(1, " ", 1);
		return (w);
	}
	return (ft_max(f->prec, len));
}

void	ft_putnbr(unsigned int num, int zero_count, int neg)
{
	int i;
	int class;
	int d;
	int count;

	write(1, "-", neg);
	while (zero_count-- > 0)
		write(1, "0", 1);
	i = ft_digit_len(num, 0);
	count = i;
	class = 1;
	d = num % 10 + 48;
	while (i-- > 1)
		class *= 10;
	while (i++ <= count && (class != 0))
	{
		d = num / class + 48;
		num %= class;
		class /= 10;
		write(1, &d, 1);
	}
}
