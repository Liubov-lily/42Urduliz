/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:05:45 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/16 15:33:38 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main (void)
{
   unsigned char src[20] = "123456fgffdfghghfgh";
 
   unsigned char dst[10] = "";
   ft_memcpy (dst, src, 3);
   printf ("dst: %s\n",dst);
   unsigned char src1[20] = "123456fgffdfghghfgh";
 
   unsigned char dst1[10] = "";
   memcpy (dst1, src1, 3);
   printf ("dst: %s\n",dst1);
   return (0);
}*/