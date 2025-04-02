/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:49:15 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/11 11:50:11 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	c = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (*str == c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>


void run_test(const char *str, int character, size_t length,
				const char *expected_result) {
    const char *result = ft_memchr(str, character, length);
1    printf("Test: String='%s', Character='%c', Length=%zu\n",
2	 		str, character, length);
    printf("Expected Result: %s\n", expected_result);
    printf("Actual Result: %s\n", result ? "Found" : "Not Found");
1   printf("Pass: %s\n\n", (result && strcmp(result, expected_result) == 0)
2	 || (!result && strcmp(expected_result, "(null)") == 0) ? "Yes" : "No");
}

int main() {
    char test1[] = "Hello, world!";
    run_test(test1, 'o', strlen(test1), "o, world!");

    char test2[] = "Hello, world!";
    run_test(test2, 'l', strlen(test2), "llo, world!");

    char test3[] = "Hello, world!";
    run_test(test3, 'z', strlen(test3), "(null)");

    char test4[] = "Hello, world!";
    run_test(test4, '!', strlen(test4) + 1, "!");

    char test5[] = "";
    run_test(test5, 'x', strlen(test5), "(null)");

    char test6[] = "Hello";
    run_test(test6, 'H', strlen(test6), "Hello");
    run_test(test6, 'e', strlen(test6), "ello");
    run_test(test6, 'o', strlen(test6), "o");
    run_test(test6, 'x', strlen(test6), "(null)");

    return 0;
}*/