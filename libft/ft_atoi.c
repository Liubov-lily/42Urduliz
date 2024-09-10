/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:16:36 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/12 13:41:28 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;

	neg = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= (-1);
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (neg * num);
}

/*#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("base atoi\n");
	printf("%d           %d\n", atoi("12345"), ft_atoi("12345"));
	printf("%d           %d\n", atoi("123ff45"), ft_atoi("123ff45"));
	printf("%d           %d\n", atoi("f123ff45"), ft_atoi("f123ff45"));
	printf("%d           %d\n", atoi("   \t -12345"), ft_atoi("   \t -12345"));
	printf("%d           %d\n", atoi("-12345"), ft_atoi("-12345"));
	printf("%d           %d\n", atoi("\n -12345"), ft_atoi("\n -12345"));
	printf("%d           %d\n", atoi(" -+12345"), ft_atoi(" -+12345"));
	printf("%d           %d\n", atoi(" +12345"), ft_atoi(" +12345"));
	printf("%d           %d\n", atoi("\f +12345"), ft_atoi("\f +12345"));
	printf("%d           %d\n", atoi("\v +12345"), ft_atoi("\v +12345"));
	printf("%d           %d\n", atoi("\r +12345"), ft_atoi("\r +12345"));
	return (0);
}*/