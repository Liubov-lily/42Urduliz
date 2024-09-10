/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:14 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/19 11:25:55 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
	{
		len = 0;
		start = lens;
	}
	if (len > lens - start)
		len = lens - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char	*str = "Hello!";
	printf("%zu\n", ft_strlen(str));
	printf(" %s   %zu\n",ft_substr(str, 1, 2), ft_strlen(ft_substr(str, 1, 2)));
	printf(" %s   %zu\n",ft_substr(str, 2, 7), ft_strlen(ft_substr(str, 2, 7)));
	printf(" %s  %zu\n",ft_substr(str, 0, 12), ft_strlen(ft_substr(str, 0, 12)));
	printf(" %s  %zu\n",ft_substr(str, 2, 15), ft_strlen(ft_substr(str, 2, 15)));
	printf(" %s   %zu\n",ft_substr(str, 1, 5), ft_strlen(ft_substr(str, 2, 5)));
	return (0);
}
*/