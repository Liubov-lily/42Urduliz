/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:14:52 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/12 13:35:19 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*des;

	len = ft_strlen(s1);
	des = malloc((len + 1) * sizeof(char));
	if (!des)
		return (NULL);
	ft_memcpy(des, s1, len + 1);
	return (des);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char	*str = "Hello World";
	printf("ft_strdup |%s|   VS   strdup|%s|\n",ft_strdup(str), strdup(str));
	str = "";
	printf("ft_strdup |%s|   VS   strdup|%s|\n",ft_strdup(str), strdup(str));
	str = "fgfgf";
	printf("ft_strdup |%s|   VS   strdup|%s|\n",ft_strdup(str), strdup(str));
	str = "\200\0";
	printf("ft_strdup |%s|   VS   strdup|%s|\n",strdup(str), strdup(str));
	return (0);
}
*/