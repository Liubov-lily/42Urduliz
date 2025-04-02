/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:56:43 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:58 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(long int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_getstr(long int num, char *str, int len)
{
	while (num > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			len;
	char		*str;

	num = n;
	len = 0;
	if (num <= 0)
	{
		len = 1;
		num *= (-1);
	}
	len += ft_numsize(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	if (n < 0)
		*str = '-';
	str[len] = '\0';
	str = ft_getstr(num, str, len);
	return (str);
}

/*int main()
{
	char	*str = ft_itoa(-123466);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/