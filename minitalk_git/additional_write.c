/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:19:54 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/01 15:14:52 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_writenum(int num)
{
	static char	ch;

	if (num > 9)
		ft_writenum(num / 10);
	ch = num % 10 + '0';
	write(1, &ch, 1);
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		ft_writenum(-num);
	}
	else
		ft_writenum(num);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
