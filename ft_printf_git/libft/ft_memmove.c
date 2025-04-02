/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:39:10 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/10 16:25:16 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s < d && d < s + len)
	{
		d += len - 1;
		s += len - 1;
		while (len > 0)
		{
			*d = *s;
			len--;
			d--;
			s--;
		}
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}

/*#include <stdio.h>  //Для printf
#include <string.h>   //Для memmove

int main (void)
{

   unsigned char s2[]="Hello";
   unsigned char s1[]="Hello";
   printf ("src1 old: %s\n",s2);
   ft_memmove (s2 + 2, s2 + 3, 2);
   printf ("src1 new: %s\n",s2);
printf("\n");
   printf ("src old: %s\n",s1);
   memmove (s1 + 2, s1 + 3, 2);
   printf ("src new: %s\n",s1);

   return 0;
}*/