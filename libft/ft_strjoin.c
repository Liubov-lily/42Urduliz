/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:01:58 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/18 13:34:58 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, lens1);
	ft_memcpy(str + lens1, s2, lens2 + 1);
	return (str);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char	*str1 = "Hello-";
	char	*str2 = "World!-";
	printf(" |%s| \n",ft_strjoin(str1, str2));
	str1 = "";
	str2 = "World!-";
	printf(" |%s|  \n",ft_strjoin(str1, str2));
	str1 = "Hello-\200";
	str2 = "";
	printf(" |%s|  \n",ft_strjoin(str1, str2));
	printf("%zu", ft_strlen(ft_strjoin(str1, str2)));
	return (0);
}*/