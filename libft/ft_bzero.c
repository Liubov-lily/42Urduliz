/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:02:18 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/09 16:22:57 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

/*#include <stdio.h>
#include <strings.h>
int	main()
{
	char	s1[5] = "Hello";
	ft_bzero(s1+2, 3);
	printf("%s\n", s1);
	char	s2[5] = "Hello";
	bzero(s2+ 1, 4);
	printf("%s\n", s2);
	return (0);
}*/