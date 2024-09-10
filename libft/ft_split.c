/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:08:11 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/19 15:53:17 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *str, char c)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		str++;
	}
	return (count);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	return (len);
}

static char	**ft_fillarr(char **arr, char const *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = ft_substr(s, i, ft_len(s, c, i));
			if (!arr[j])
			{
				ft_free(arr);
				return (NULL);
			}
			i = i + ft_len(s, c, i);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_countwords((char *)s, c) + 1));
	if (!arr)
		return (NULL);
	arr = ft_fillarr(arr, s, c);
	return (arr);
}

/*int main()
{
	int i = 0;
	char **arr = ft_split("xxxxxxxxhello!", 'x');
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/