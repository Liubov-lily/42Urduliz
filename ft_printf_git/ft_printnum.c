/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:43:54 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/26 12:02:50 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(long int num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static void	ft_putnum(long int num)
{
	static char	ch;

	if (num > 9)
		ft_putnum(num / 10);
	ch = num % 10 + '0';
	write(1, &ch, 1);
}

int	ft_printnum(long int num, int len)
{
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num == 0)
		len++;
	ft_putnum(num);
	return (len + ft_size(num));
}
