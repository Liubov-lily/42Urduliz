/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:26:31 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/11 11:04:22 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>

int main()
{
	char	*str = "Abcdefghigklmnop";
	char	*str1 = "Abcdefghigklmnop";
	printf("%s\n", strchr(str, 'e'));
	printf("%s\n", str);
	printf("%s\n", ft_strchr(str1, 'e'));
	printf("%s\n", str1);
	return (0);
}
*/