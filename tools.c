/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:49:03 by mskeleto          #+#    #+#             */
/*   Updated: 2021/01/27 12:59:07 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		mod(int n)
{
	return (n * (1 - 2 * (n < 0)));
}

int					ft_max(int a, int b)
{
	return ((a >= b) * a + (b > a) * b);
}

int					ft_digit_len(unsigned int n, unsigned int minus)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + minus);
}

unsigned long long	ft_pow(unsigned long num, int len)
{
	unsigned long long n;

	n = 1;
	while (len-- > 0)
		n *= num;
	return (n);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
