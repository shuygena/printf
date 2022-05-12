/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:13:19 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/26 21:49:56 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s, int w, int p)
{
	if (s == NULL && w < 0)
		return (ft_str_align(mod(w), p, "(null)"));
	if (s == NULL)
		return (ft_str_out(w, p, "(null)"));
	if (s != NULL && w < 0)
		return (ft_str_align(mod(w), p, s));
	return (ft_str_out(w, p, s));
}

int	ft_str_out(int wid, int prec, char *s)
{
	int i;

	i = 0;
	if (wid > prec && prec < ft_strlen(s) && prec >= 0)
	{
		while ((wid - prec) > i++)
			write(1, " ", 1);
		write(1, s, prec);
		return (wid);
	}
	if (wid > ft_strlen(s))
	{
		while ((wid - ft_strlen(s)) > i++)
			write(1, " ", 1);
		write(1, s, ft_strlen(s));
		return (wid);
	}
	if (prec < ft_strlen(s) && prec >= 0)
	{
		write(1, s, prec);
		return (prec);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_str_align(int wid, int prec, char *s)
{
	int i;

	i = 0;
	if (wid > prec && prec < ft_strlen(s) && prec >= 0)
	{
		write(1, s, prec);
		while ((wid - prec) > i++)
			write(1, " ", 1);
		return (wid);
	}
	if (wid > ft_strlen(s))
	{
		write(1, s, ft_strlen(s));
		while ((wid - ft_strlen(s)) > i++)
			write(1, " ", 1);
		return (wid);
	}
	if (prec < ft_strlen(s) && prec >= 0)
	{
		write(1, s, prec);
		return (prec);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_ch_out(int wid, char c)
{
	int i;

	i = 1;
	if (wid < -1)
	{
		write(1, &c, 1);
		wid *= -1;
		while (i++ < wid)
			write(1, " ", 1);
		return (wid);
	}
	if (wid > 1)
	{
		while (i++ < wid)
			write(1, " ", 1);
		write(1, &c, 1);
		return (wid);
	}
	write(1, &c, 1);
	return (1);
}
