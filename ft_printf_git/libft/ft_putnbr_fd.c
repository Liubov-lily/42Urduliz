/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:32:22 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/17 10:31:47 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenum(long int n, int fd)
{
	if (n > 9)
		ft_writenum(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	ft_writenum(num, fd);
}

/*int main()
{
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(-12345, 1);
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/