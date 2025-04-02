/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:33:07 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/11 13:15:59 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *s1 == *s2 && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char *s1 = "abccdef\200";
	char *s2 = "abccdef\0";
	printf("%d\n",strncmp(s1, s2, 8));
	printf("%d\n",ft_strncmp(s1, s2, 8));
	return (0);
}
*/