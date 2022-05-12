/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:56:21 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 19:38:56 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_out(int i, t_format *f, unsigned long long n)
{
	int	len;

	if (n == 0 && f->prec == 0)
	{
		while (i++ < f->wid - 2)
			write(1, " ", 1);
		write(1, "0x", 2);
		return (ft_max(f->wid, 2));
	}
	len = ft_hex_len(n);
	if (f->wid > len + 2)
	{
		while (i++ < f->wid - len - 2)
			write(1, " ", 1);
		write(1, "0x", 2);
		ft_put_hex(n, len, 'x', 0);
		return (f->wid);
	}
	write(1, "0x", 2);
	ft_put_hex(n, len, 'x', 0);
	return (len + 2);
}

int	ft_p_align(int w, int i, t_format *f, unsigned long long n)
{
	int	len;

	if (f->prec == 0 && n == 0)
	{
		write(1, "0x", 2);
		while (i++ < w - 2)
			write(1, " ", 1);
		return (ft_max(w, 2));
	}
	len = ft_hex_len(n);
	write(1, "0x", 2);
	ft_put_hex(n, len, 'x', 0);
	if (w > len + 2)
	{
		while (i++ < (w - len - 2))
			write(1, " ", 1);
		return (w);
	}
	return (len + 2);
}

int	ft_percent(t_format *f)
{
	int i;

	i = 0;
	if (f->wid > 1)
	{
		while ((i < (f->wid - 1)) && f->zero == 48)
		{
			write(1, "0", 1);
			++i;
		}
		while ((i < (f->wid - 1)) && f->zero != 48)
		{
			write(1, " ", 1);
			i++;
		}
	}
	write(1, "%", 1);
	if (f->wid < -1)
	{
		while ((i++ < ((int)mod(f->wid) - 1)))
			write(1, " ", 1);
	}
	return (ft_max(1, mod(f->wid)));
}
