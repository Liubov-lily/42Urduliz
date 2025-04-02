/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:46:11 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/11 11:07:10 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	c = (char)c;
	str = (char *)s;
	while (*s != '\0')
		s++;
	while (str != (char *)s && *s != c)
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>

int main()
{
	char	*str = "Abcdefghiogklmnop";
	char	*str1 = "Abcdefghoigklmnop";
	printf("%s\n", strrchr(str, 'o'));
	printf("%s\n", str);
	printf("%s\n", ft_strrchr(str1, 'o'));
	printf("%s\n", str1);
	return (0);
}*/