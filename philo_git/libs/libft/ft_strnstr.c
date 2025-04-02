/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:53:27 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/12 12:11:03 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len >= nlen)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(haystack, needle, nlen) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>


// Function to run tests
void run_tests() {
    // Test case 1: Needle is found within haystack
    char haystack1[] = "Hello, World!";
    char needle1[] = "World";
    char *result1 = ft_strnstr(haystack1, needle1, strlen(haystack1));
    char *result2 = strnstr(haystack1, needle1, strlen(haystack1));
    printf("Test 1:  %s   %s\n", result1, result2);

    // Test case 2: Needle is not found within haystack
    char haystack2[] = "Hello, World!";
    char needle2[] = "Bonjour";
    result1 = ft_strnstr(haystack2, needle2, strlen(haystack2));
    result2 = strnstr(haystack2, needle2, strlen(haystack2));
    printf("Test 2:  %s    %s\n", result1, result2);

    // Test case 3: Needle is empty string
    char haystack3[] = "Hello, World!";
    char needle3[] = "";
    result1 = ft_strnstr(haystack3, needle3, strlen(haystack3));
    result2 = strnstr(haystack3, needle3, strlen(haystack3));
    printf("Test 3:  %s    %s\n", result1, result2);

    // Test case 4: Needle is longer than haystack
    char haystack4[] = "Hello, World!";
    char needle4[] = "Hello, World!Bonjour";
    result1 = ft_strnstr(haystack4, needle4, strlen(haystack4));
    result2 = strnstr(haystack4, needle4, strlen(haystack4));
    printf("Test 4:   %s    %s\n", result1, result2);

    // Test case 5: Needle is equal to haystack
    char haystack5[] = "Hello, World!";
    char needle5[] = "Hello, World!";
    result1 = ft_strnstr(haystack5, needle5, strlen(haystack5));
    result2 = strnstr(haystack5, needle5, strlen(haystack5));
    printf("Test 5:   %s    %s\n", result1, result2);

	 // Test case 6: Needle is equal to haystack
    char haystack6[] = "Hello, World!";
    char needle6[] = "Hello, World!";
    result1 = ft_strnstr(haystack6, needle6, 3);
    result2 = strnstr(haystack6, needle6, 3);
    printf("Test 6:   %s    %s\n", result1, result2);

    // Test case 7: Needle is found within haystack
    char haystack7[] = "Hello, WWorld!";
    char needle7[] = "World";
    result1 = ft_strnstr(haystack7, needle7, strlen(haystack7));
    result2 = ft_strnstr(haystack7, needle7, strlen(haystack7));
    printf("Test 7  %s    %s\n", result1, result2);

    // Test case 8: Needle is found within haystack
    char haystack8[] = "Hello, World!";
    char needle8[] = "WorlS";
    result1 = ft_strnstr(haystack8, needle8, strlen(haystack8));
    result2 = ft_strnstr(haystack8, needle8, strlen(haystack8));
    printf("Test 8  - Result:   %s    %s\n", result1, result2);
}

int main() {
    run_tests();
    return 0;
}*/