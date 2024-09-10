/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:49:23 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/09 14:42:48 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}

/*#include <stdio.h>
#include <string.h>

int	main ()
{
   char	str[] = "This is string.h library function";
   char	str1[] = "This is string.h library function";

   printf("%s\n", str);
   ft_memset(str, '1', 3);
   memset(str1, '1', 3);
   printf("%s\n", str);
   printf("%s\n", str1);
   return(0);
}*/