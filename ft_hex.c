/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:31:58 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 19:33:57 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_out(int i, t_format *f, unsigned int n, char z)
{
	int len;

	if (n == 0 && f->prec == 0)
	{
		while (i++ < f->wid)
			write(1, " ", 1);
		return (f->wid);
	}
	len = ft_hex_len(n);
	if ((z != '0' || f->prec >= 0) && f->wid > f->prec && f->wid > len)
	{
		while (i++ < f->wid - (ft_max(f->prec, len)))
			write(1, " ", 1);
		ft_put_hex(n, len, f->type, (f->prec - len));
		return (f->wid);
	}
	if (f->wid > len && z == 48 && f->prec < 0)
	{
		ft_put_hex(n, len, f->type, (f->wid - len));
		return (f->wid);
	}
	ft_put_hex(n, len, f->type, (f->prec - len));
	return (ft_max(f->prec, len));
}

int		ft_hex_align(int w, int i, t_format *f, unsigned int n)
{
	int len;

	if (f->prec == 0 && n == 0)
	{
		while (i++ < w)
			write(1, " ", 1);
		return (w);
	}
	len = ft_hex_len(n);
	ft_put_hex(n, len, f->type, (f->prec - len));
	if (w > f->prec && w > len)
	{
		while (i++ < (w - (ft_max(f->prec, len))))
			write(1, " ", 1);
		return (w);
	}
	return (ft_max(f->prec, len));
}

int		ft_hex_len(unsigned long long num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned long long num, int len, char low_up, int z)
{
	unsigned long long	div;
	char				digit;

	while (z-- > 0)
		write(1, "0", 1);
	div = ft_pow(16, (len - 1));
	while (len-- > 1)
	{
		digit = num / div;
		if (digit < 10)
			digit += 48;
		else
			digit = digit % 10 + low_up - 23;
		write(1, &digit, 1);
		num %= div;
		div /= 16;
	}
	digit = num / div;
	if (digit < 10)
		digit += 48;
	else
		digit = digit % 10 + low_up - 23;
	write(1, &digit, 1);
}

int		ft_ft(int wid, int minus)
{
	if (minus == 1)
		return (mod(wid) * -1);
	return (wid);
}
