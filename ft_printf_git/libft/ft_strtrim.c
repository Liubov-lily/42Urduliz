/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:51:23 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/18 14:12:43 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_isset(char ch, char *set)
{
	while (*set != '\0')
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}*/

static int	ft_find_pos(char const *s1, char const *set, int i)
{
	if (i == 0)
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
	}
	else
	{
		while (ft_strchr(set, s1[i]) && i > 0)
			i--;
	}
	return (i);
}

static char	*ft_ifzerolen(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str)
		*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_ifzerolen());
	start = 0;
	end = len - 1;
	start = ft_find_pos(s1, set, start);
	end = ft_find_pos(s1, set, end);
	if (start > end)
		return (ft_ifzerolen());
	else
	{
		end++;
		str = malloc((end - start + 1) * sizeof(char));
		if (str)
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

/*
		//ft_memcpy(str, start, end - start);
		//str[end - start] = '\0';
		int main()
{
	char	*str = "123hello123";
	char	*set = "123";
	printf("1 test: %s\n",ft_strtrim(str,set));
	str = "123hello123";
	set = "456";
	printf("2 test: %s\n",ft_strtrim(str,set));
	str = "456654";
	set = "456";
	printf("3 test: %s\n",ft_strtrim(str,set));
	str = "123hel4lo123";
	set = "";
	printf("4 test: %s\n",ft_strtrim(str,set));
	str = "123123123h";
	set = "123";
	printf("5 test: %s\n",ft_strtrim(str,set));
	str = "m123123123123";
	set = "123";
	printf("6 test: %s\n",ft_strtrim(str,set));
	return (0);
}*/
/*char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_ifzerolen());
	start = (char *)s1;
	end = (char *)(s1 + len - 1);
	while (*start != '\0' && ft_isset(*start, (char *)set) == 1)
		start++;
	while (ft_isset(*end, (char *)set) == 1 && end != s1)
		end--;
	if (start > end)
		return (ft_ifzerolen());
	else
	{
		end++;
		str = malloc((end - start + 1) * sizeof(char));
		if (str)
			ft_strlcpy(str, start, end - start + 1);
	}
	return (str);
}*/