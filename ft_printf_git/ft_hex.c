/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:15:21 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/26 11:21:47 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned long long num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

static void	ft_cstr(unsigned long long num, int lowupp)
{
	static char	ch;

	if (num > 15)
		ft_cstr(num / 16, lowupp);
	if (num % 16 < 10)
		ch = num % 16 + '0';
	else
	{
		if (lowupp == 1 || lowupp == 3)
			ch = (num % 16) % 10 + 'a';
		else
			ch = (num % 16) % 10 + 'A';
	}
	write(1, &ch, 1);
}

int	ft_hex(unsigned long long num, int lowupp)
{
	int	size;

	size = 0;
	if (num == 0)
		size = 1;
	if (lowupp == 3)
		size += write(1, "0x", 2);
	if (num < 0)
	{
		num *= -1;
		size += write(1, "-", 1);
	}
	ft_cstr(num, lowupp);
	size += ft_size(num);
	return (size);
}
